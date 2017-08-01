#include <iostream>

// File  : fibonacci_last_digit.cpp
// Implements algorithm to output only the digit in unit place for n'th fibonacci number
// Has both naive as well as a faster version of the algorithm

// Naive algorithm with a loop
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

// Faster version with memoization
int get_fibonacci_last_digit_fast(int n){
    int f[n];
    f[0] = 0;
    f[1] = 1;

    for(int i=2;i<=n;i++){
        f[i]=((f[i-1]+f[i-2])%10);
    }

    return f[n];
}

// Main program that calls both algorithms
int main() {
    int n ;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_naive(n) << '\n';
    std::cout << get_fibonacci_last_digit_fast(n) << '\n';
}
