#include <iostream>

// File :fibonacci_sum_last_digit.cpp
// Implements an algorithm to compute the sum of n Fibonacci numbers
// returns the unit place digit of the sum

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
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

int fibonacci_sum_fast(long long n) {
   
    // using fact - (Fn mod m) = F(n mod pisano_period) mod m 
    int pisano_period = get_pisano_period(10);
    long long  fib_n = (long long) (n%pisano_period);

    // now allocate a smaller array size required
    int F[fib_n];
    F[0] = 0;
    F[1] = 1;

    int sum = 1;

    if(fib_n==0){
        sum=0;
    }

    // compute : F(n mod pisano_period) mod 10
    for(int i=2; i<=fib_n; i++){
        F[i]=((F[i-1]+F[i-2])%10); 
        sum = sum+F[i];       
    }

    return sum%10;
}


// Main program calls the fast algorithm
int main() {
    long long n = 0;
    std::cin >> n;
   
    std::cout << fibonacci_sum_fast(n)<<std::endl;
}
