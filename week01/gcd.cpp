#include <iostream>

// File : gcd.cpp
// Implements naive and euclidean method to get GCD of two positive numbers
// GCD is the greatest number that divides both the numbers.

// naive algorithm 
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


// Euclidean algorithm using remainder method
int gcd_euclidean(int a , int b){

  if(b==0){
    return a;
  }
  else if (a >= b && b > 0) {
    return gcd_euclidean(b, (a%b));
  }
  else if (b >= a && a > 0) {
    return gcd_euclidean(a, (b%a));
  }

}

// Main program calls both algorithms 
int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_euclidean(a, b) << std::endl;
  return 0;
}
