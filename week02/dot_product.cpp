#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

// File  : dot_product.cpp
// Maximize online ad profits
// Need to organise (a,b) passed to groups such that 
// we maximize the sum of their products

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  std::sort(a.begin(),a.end()); 
  std::sort(b.begin(),b.end());  
  long long result = 0;

  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

// test stub
void test(){
  int n = 3;
  vector<int> a(n), b(n);
  a.push_back(1);
  a.push_back(3);
  a.push_back(-5);

  b.push_back(-2);
  b.push_back(4);
  b.push_back(1);

  assert(max_dot_product(a,b)==23);
}

int main() {
  size_t n;  
  std::cin >> n;
  vector<int> a(n), b(n);
  
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::cout << max_dot_product(a, b) << std::endl;
}
