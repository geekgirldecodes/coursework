#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <limits>

using std::vector;

// File  : fractional_knapsack.cpp
// Implements an algorithm to output the maximal value of fractions of items 
// that fit into the knapsack

//structure to hold info required per item, value, weight, value per unit weight
typedef struct ks_elem_t{
  int value;
  int weight;
  double val_per_unit_wt;
}ks_elem_t;


// custom comparator defined to arrange values in the vector based on
// value per unit weight
typedef struct greater_t
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a.val_per_unit_wt > b.val_per_unit_wt; }
}greater_t;


// Greedy method to obtain the maximized value for a given Capacity
// given a set of items with weights and corresponding values.
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

  double value = 0.0;
  if(values.size()!=weights.size()){
    return -1;
  }
  
  //compute the value per weight array
  vector<ks_elem_t> ks_vector;
  for(int i=0; i < weights.size(); i++){
     ks_elem_t ks_e;
     ks_e.value = values.at(i);
     ks_e.weight = weights.at(i);
     ks_e.val_per_unit_wt = (double)values.at(i)/weights.at(i);
     ks_vector.push_back(ks_e);
  }

  // sort the vector using custom comparator
  std::sort(ks_vector.begin(),ks_vector.end(),greater_t());
  int j =0;
  double frac = 0;

  // traverse the vector by value per unit weight and apply greedy strategy
  for(j=0;j<ks_vector.size();j++){
    if( capacity == 0)
      return value;
    else{   
      double wj = ks_vector.at(j).weight ;
      
      if(wj> 0) {
        frac = std::min(ks_vector.at(j).weight, capacity);
        value = value+ frac* (ks_vector.at(j).val_per_unit_wt);
        wj = wj - frac;
        capacity = capacity-frac;        
      }
    }
  }  
  return value;
}

void test(){
  // Custom Test data
    int capacity=16;
    vector<int> values(6);
    vector<int> weights(6);

    values.push_back(6);
    values.push_back(2);
    values.push_back(1);
    values.push_back(8);
    values.push_back(3);
    values.push_back(5);


    weights.push_back(6);
    weights.push_back(10);
    weights.push_back(3);
    weights.push_back(5);
    weights.push_back(1);
    weights.push_back(3);
  
    double optimal_value = get_optimal_value(capacity, weights, values);
    std::cout<<std::numeric_limits<double>::epsilon()<<std::endl;
    double expected = 61/3; // 20.333333
    std::cout<<"opt "<<optimal_value<<" "<<(optimal_value- expected)<<std::endl;
    assert((std::fabs(optimal_value- (double)22.3333)) <= std::numeric_limits<double>::epsilon());
    std::cout<<"Test passed " <<std::endl;
}

// Main program that takes capacity, weights and values as inputs
// output the maximized value
int main() {
  int n;
  int capacity;

  std::cin >> n >> capacity;

  vector<int> values(n);
  vector<int> weights(n);
  
  // read input
  for (int i = 0; i < n; i++) {
      std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  
  std::cout << std::fixed;
  std::cout<<std::setprecision(10);
  std::cout<<(double)optimal_value << std::endl;

  return 0;
}
