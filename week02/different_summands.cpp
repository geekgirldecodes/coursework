#include <iostream>
#include <vector>
#include <cassert>

// File  : different_summands.cpp
// Implements an algorithm to represent a given positive integer n as a sum of as many pairwise
// distinct positive integers as possible

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int l = 1;int k = n;

  while(k>0){

    if(k <= 2*l){
        summands.push_back(k);
        break;
    }
    else{
     summands.push_back(l);
     k = k-l;
     l = l+1;
    }
  }
  
  return summands;
}

void test(){
  //test 01
  int n = 6;
  vector<int> summands = optimal_summands(n);
  assert(summands[0] == 1);
  assert(summands[1] == 2);
  assert(summands[2] == 3);
  std::cout<<"Test 01 pass"<<std::endl;

  //test 02
  n = 2;
  summands = optimal_summands(n);
  assert(summands[0] == 2);
  std::cout<<"Test 02 pass"<<std::endl; 
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
