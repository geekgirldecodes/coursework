#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

// File : binary_search.cpp
// Implements an algorithm to find a key using binary search algorithm
// Binary search works on the assumption that the data is sorted 

// Binary search takes O(logn)
int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1; 
  int mid =0;

  while(left < right && mid != left){
    mid = (left+right)/2;
     std::cout<<"Inner "<<left<<" "<<right<<" "<<mid<<std::endl;
    if(a[mid] == x){
      return mid;
    }
    else if(x < a[mid]){
      right = mid;
    }
    else if(x > a[mid]){
      left = mid;
    }
  }

  return -1;
}

// linear search takes O(n)
int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

// test stubs 
void test(){

  vector<int> sample;
  //sorted sample input data 
  sample.push_back(1);
  sample.push_back(5);
  sample.push_back(8);
  sample.push_back(12);
  sample.push_back(13);

  // keys to be searched for in the array
  vector<int> keys;
  keys.push_back(8);
  keys.push_back(1);
  keys.push_back(23);
  keys.push_back(1);
  keys.push_back(11);

  // validate output 
  for(int i=0; i < keys.size();i++){
    std::cout<<binary_search(sample, keys.at(i))<<std::endl;
    assert( 2 == binary_search(keys.at(0)));
    assert ( -1 == binary_search(keys.at(2)));
    assert(0 == binary_search(1));
  }

}


int main() {
  int n ;
  test();
  /*
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
  }
  */
}
