#include <iostream>
#include <cassert>

// File  : fibonacci.cpp
// Implements a naive and an optimized memoization based algorithm 
// to find nth fibonacci number

//Naive algorithm with recursion
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// Fast algorithm based on memoization
int fibonacci_fast(int n) {
    int f[n];
    // write your code here
     f[0]= 0;
     f[1]= 1;
     int i =0;
      for(i=2;i<=n;i++){
        f[i] = f[i-1]+f[i-2];        
     }
    
    return f[n];
}

// Test stub to test the solution and 
// compare output from naive and fast algorithms
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

// Main program that takes a number n, and prints the n'th fibonacci number.
int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_naive(n) << '\n';
    test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
