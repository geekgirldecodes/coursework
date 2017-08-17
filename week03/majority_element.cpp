#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

// File : majority_element.cpp
// Implements an algorithm to check if an input contains a majority element
// This is a divide and conquer approach to majority element
// Assumption is that the input array contains only non negative numbers 


//helper function to get the frequency of occurence of given element
unsigned int get_frequency(const vector<int> &a, int left, int right, int element)
{
  unsigned int counter = 0;
  for (unsigned int i = left; i <= right; i++)
  {
    if (a[i] == element)
    {
      counter++;
    }
  }
  return counter;
}

// implementation of divide and conquer algorithm
int get_majority_element(vector<int> &a, int left, int right) {
  
  // end of recursion case
  if (left > right) return -1;
  if (left == right) return a[left];

  // divide and conquer to find the majority element
  int mid = left + (right - left) / 2;
  int left_elem = get_majority_element(a, left, mid);
  int right_elem = get_majority_element(a, mid + 1, right);

  // handle various cases 
  if (left_elem == -1 && right_elem != -1)
  {
    unsigned int rfreq = get_frequency(a, left, right, right_elem);

    if (rfreq > (right - left + 1) / 2)
    {
      return right_elem;
    }
    else
    {
      return -1;
    }

  }
  else if (right_elem == -1 && left_elem != -1)
  {
    unsigned int lfreq = get_frequency(a, left, right, left_elem);
    if (lfreq > (right - left + 1) / 2)
    {
      return left_elem;
    }
    else
    {
      return -1;
    }
  }
  else if (left_elem != -1 && right_elem != -1)
  {
    unsigned int lfreq = get_frequency(a, left, right, left_elem);
    unsigned int rfreq = get_frequency(a, left, right, right_elem);

    if (lfreq > (right - left + 1) / 2)
    {
      return left_elem;
    }
    else if (rfreq> (right - left + 1) / 2)
    {
      return right_elem;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return -1;
  }

}

// Tests to be performed 
void test(){

  // no majority element
  vector<int> test1;
  test1.push_back(717383758);
  test1.push_back(5);
  test1.push_back(126144732);
  test1.push_back(51);
  test1.push_back(573799007);
  test1.push_back(5);
  test1.push_back(5);
  test1.push_back(5);
  test1.push_back(405079772);
  assert(get_majority_element(test1, 0, test1.size()-1) == -1);
  
  // has majority element
  vector<int> test2;
  test2.push_back(2);
  test2.push_back(2);
  assert(get_majority_element(test2, 0, test2.size()-1) != -1);

}

int main() {
  
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
