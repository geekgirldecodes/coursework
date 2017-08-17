#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using std::vector;
using std::string;

using namespace std;

// File : largest_number.cpp
// Implements algorithm to compose the largest number out of a set of integers

int greater_t(string a, string b)
{
    // form string ab
    string ab = a.append(b);
 
    // form string ba 
    string ba = b.append(a);
 
    // check which is greater
    return ab.compare(ba) > 0 ? 1: 0;
}

// algorithm with custom comparator to find the largest number with given set of integers
string largest_number(vector<string> a) {
  //arrange the numbers given based on the highest place digit 
  std::sort(a.begin(),a.end(), greater_t);  
  std::stringstream ret;

  // result is just a concatenation of all the 
  // numbers once arranged in descending order
  for(size_t i=0 ; i <a.size(); i++){
      ret << a[i];
  }
  
  string result;
  ret >> result;
  return result;
}

// Test stub to test the algorithm
void test(){

  vector<string> a;
  a.push_back("21");
  a.push_back("2");
  assert(largest_number(a) == "221");
  std::cout<<"Test passed "<<std::endl;
}

int main() {
  int n;

  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
 std::cout << largest_number(a);
 
}
