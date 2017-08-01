#include <iostream>

// File : lcm.cpp
// Implements naive and GCD based algorithm to find the LCM of two positive numbers
// LCM  is least common multiplier, a number that is DIVISIBLE by both numbers
// LCM(a,b) can be computed using GCD : lcm(a,b) = (a*b)/gcd(a,b)

// Naive algorithm , go through every number from 1 to a*b 
// Check which is divisible by both a and b
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

// Helper gcd function for faster lcm algorithm
long long gcd_euclidean(int a , int b){

  if(b==0){
    return (long long)a;
  }
  else if (a >= b && b > 0) {
    return (long long)gcd_euclidean(b, (a%b));
  }
  else if (b >= a && a > 0) {
    return (long long)gcd_euclidean(a, (b%a));
  }

}

// Optimized way to compute lcm using gcd internally
long long lcm_optimized(int a, int b){
	int gcd = gcd_euclidean(a,b);
	return (long long)a*b/gcd;
}

// Main code that tests both algorithms
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_optimized(a, b) << std::endl;
  return 0;
}
