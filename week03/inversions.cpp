#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

// File : inversions.cpp
// This file implements a merge_sort() based algorithm to 
// count the number of inversions required to sort the array


// merge function for merge_sort 
// takes two arrays, provided as indices and makes a merged array 
long long merge(vector<int> &a,vector<int> &b, int left, int mid, int right) 
{ 

  // declare locals
  int l, r, m;
  long long inv_count =0;

  l = left; // index to left sub array 
  r = mid;  // index to right sub array 
  m = left; // index to merged array  

  while( l <= mid-1 && r <= right){
    if(a[l] <= a[r]){
      b[m++] = a[l++];
    }
    else{
      b[m++] =  a[r++];
      // trick  here :
      // when we find an element in left array b , that is greater than right array element c 
      // remaining mid-l , are the number of inversions required 
      inv_count = inv_count+(mid-l);
    }
  }

  // append remaining numbers 
  while(l <= mid-1){
    b[m++]= a[l++];
  }

  // append remaining numbers 
  while(r <= right){
    b[m++] = a[r++];
  }

  // copy back to input array 
  for (int i=left; i <= right; i++){
    a[i] = b[i];
  }

 return (long long)inv_count; 
}

// this is modified merge_sort to find the number of inversions required
long long get_number_of_inversions(vector<int> &a , vector<int> &b , int left , int right){

  long long number_of_inversions =0;
  // exit condition
  if(right > left ){
    // recursively merge sort 
    int mid = left + (right -left)/2;
    number_of_inversions = (long long)get_number_of_inversions(a,b, left, mid);
    number_of_inversions += (long long)get_number_of_inversions(a,b, mid+1,right);
    number_of_inversions += merge(a,b, left,mid+1,right);
  }

  return (long long)number_of_inversions;
}

// Test cases
void test(){

  vector<int> test1;
  test1.push_back(1);
  test1.push_back(2);
  test1.push_back(3);
  test1.push_back(4);
  vector<int> output1(test1.size());
  assert(0==get_number_of_inversions(test1, output1, 0, test1.size()-1));
  std::cout<<"Test1 passed "<<std::endl;

  vector<int> test2;
  test2.push_back(2);
  test2.push_back(3);
  test2.push_back(9);
  test2.push_back(2);
  test2.push_back(9);
  vector<int> output2(test2.size());
  assert(2==get_number_of_inversions(test2, output2, 0, test2.size()-1));
  std::cout<<"Test2 passed "<<std::endl;

}


int main() {

  int n;
  std::cin >> n;
    
  // input array
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  // b is the sorted output vector
  vector<int> b(a.size());

  std::cout << (long long) get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
