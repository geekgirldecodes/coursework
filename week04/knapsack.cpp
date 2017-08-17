#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

// File : knapsack.cpp
// Implements a dynamic programming based algorithm to solve the 
// 0/1 knapsack problem
// Output the max weight that can be carried in a bag of capacity W 
// note unique items (no associated value , only weights givem)

// greedy approach
int optimal_weight_greedy(int W, const vector<int> &w) {
  
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}


// DP based approach
// implements a memoization based DP algorithm 
int optimal_weight(int W, const vector<int> &wt ){

  vector<int> K(W+1); // memoizationn vector initialized to zero.
  
  for (size_t i = 0; i < wt.size(); ++i) {
    for(int j = W; j - wt[i] >= 0; --j) {
      K[j] = std::max(K[j], K[j - wt[i]] + wt[i]);
      //std::cout<<"K["<<j<<"]="<<K[j]<<std::endl;
    }
  }

  return K[W];
}

//test stub for sample input
void test(){
  int W = 10;
  vector<int> w;
  w.push_back(1);
  w.push_back(4);
  w.push_back(8);

  assert(9==optimal_weight(W, w));
  std::cout<<"Test passed "<<std::endl;
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
