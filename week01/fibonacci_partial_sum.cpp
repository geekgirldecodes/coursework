#include <iostream>
#include <vector>
using std::vector;

// File :fibonacci_partial_sum.cpp
// Implements an algorithm to compute the sum of Fibonacci numbers in a given range
// Returns only unit place digit of the sum

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
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

int get_fibonacci_partial_sum_fast(long long from, long long to) {
   
    // using fact - (Fn mod m) = F(n mod pisano_period) mod m 
    int pisano_period = get_pisano_period(10);
    long long  fib_m = (long long) (from%pisano_period);
    long long  fib_n = (long long) (to%pisano_period);

    //std::cout<<"fib_m and fib_n "<<fib_m <<" "<<fib_n<<std::endl;
    // now allocate a smaller array size required
    int Fm[fib_m+1];
    int range = (fib_n- fib_m) +1;

    //subset array to compute subset sum
    int F[range];
    int sum = 0;
    int i = 0;

    // intialize first two fib numbers
    Fm[0]=0;
    Fm[1]=1;

    // Calculate upto (m+1)th fib number
    for(i=2; i<=fib_m+1 ;i++){
        Fm[i]=((Fm[i-1]+Fm[i-2])%10);
    }

    // we need the fib array to hold fib numbers in the range m to n
    F[0] = Fm[i-2];
    F[1] = Fm[i-1];

    // in case fib_m == fib_n , sum is number at index indicated by "from"
    sum = F[0];

    if(fib_n != fib_m){
        sum = F[0]+F[1];
        // compute : F(n mod pisano_period) mod 10
        for(int i=2; i<fib_n-fib_m+1; i++){
            F[i]=((F[i-1]+F[i-2])%10);
            sum = sum+F[i];       
        }
    }

    //return the unit place digit of the subset sum
    return sum%10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
