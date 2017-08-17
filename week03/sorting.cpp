#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

// File : sorting.cpp
// Implements a 3-way partition based quick sort algorithm

//implements 3-way partition algo
void partition3(vector<int> &a, int l, int r, int &m1 , int &m2) {
  int x = a[l]; // pivot is the left most element
  m1 = l; // initialize to left most index
  m2 = r; // initialize to right most index +1
  int i = l; // start from after pivot 

  while(i <= m2){
    if(a[i] < x){
      // element less than pivot 
      swap(a[i],a[m1]);
      m1++;
      i++;
    }
    else if (a[i] > x){    
      swap(a[i],a[m2]);
       m2--;  
    }
    else{
      i++;
    }
  }
}


// implements 2-way partition algo 
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);

  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  } 

  int k = l + rand() % (r - l + 1);
  //pick pivot randomly and make it the left most element
  swap(a[l], a[k]);

  // use 3-way partition algo
  int m1 , m2;
  partition3(a, l, r,m1 ,m2);

  // recursive calls to quick sort based on indices returned from 3-way partition algo m1 and m2
  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

//test stub to check if  3 way algo works 
void test(){
  vector<int> a;
  a.push_back(2);
  a.push_back(3);
  a.push_back(9);
  a.push_back(2);
  a.push_back(9);
  randomized_quick_sort(a,0, a.size()-1);

  for(int j=0;j<a.size();j++){
    std::cout<<a[j]<<std::endl;
  }

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  randomized_quick_sort(a,0, a.size()-1);

  for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i] << ' ';
  }
}
