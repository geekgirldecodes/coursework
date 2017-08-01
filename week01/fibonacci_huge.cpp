
#include <iostream>

// File :fibonacci_huge.cpp
// implements algorithm to compute Fn mod m 
// Finds the pisano period for a given input m 
// Implements faster algorithm to compute Fn mod m using pisano_period 

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// compute the pisano period to reduce computations
// let p = pisano period for a modulo factor m

long long get_pisano_period(long long m) {

    long long fib_n_1 = 0, fib_n_2 = 1, fib_n = fib_n_1 + fib_n_2;

    // Trick fact : Pisano period of number m , is less than m*m
    for (int period = 0; period < m * m; period++) {
        // mod the nth fib with "m"
        fib_n = (fib_n_1 + fib_n_2) % m;
        fib_n_1 = fib_n_2;
        fib_n_2 = fib_n;

        // Use fact : Pisano period , sequence repeats starting with 0,1 ...
        if (fib_n_1 == 0 && fib_n_2 == 1){
            return (long long)(period + 1);
        }
    }
}

// Faster algorithm using memoization
long long get_fibonacci_huge_fast(long long n, long long m) {

    // using fact - (Fn mod m) = F(n mod pisano_period) mod m 
    int pisano_period = get_pisano_period(m);
    long long  fib_n = (long long) (n%pisano_period);

    // now allocate a smaller array size required
    long long F[fib_n];
    F[0] = 0;
    F[1] = 1;

    // compute : F(n mod pisano_period) mod m
    for(int i=2; i<=fib_n; i++){
        F[i]=(long long)((F[i-1]+F[i-2])%m);         
    }

    return (long long)F[fib_n];
}

// Main program that uses both algorithms
int main() {
    long long n, m;
    std::cin >> n >> m;
    // this will take way longer than the fast version
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << (long long) get_fibonacci_huge_fast(n, m) << '\n';
}
