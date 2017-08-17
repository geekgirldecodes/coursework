#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <limits>

// File  : change.cpp
// find the minimum number of coins needed to change the input value
// (an integer) into coins with denominations 1, 5, and 10.

int get_change(int m) {
	uint8_t denom_5 = 5, denom_10=10, denom_1=1;
	int n =0;

	if(m ==0){
		return n;
	}

   //algorithm starts here
	while(m != 0){
		if(m >= denom_10){
			m=m-denom_10;
		    n++;
		}
		else if(m >= denom_5){
			m=m-denom_5;
		    n++;
		}
		else if(m >=denom_1){
			m=m-denom_1;
		    n++;
		}
		else{
			m = 0; //reset m to exit
			n = -1; // none of the known denominations work
		}
	}
  return n;
}

void test(){
  // Custom Test data
  assert(get_change(28) == 6);
  std::cout<<"Test passed " <<std::endl;
}

int main() {
  int m ;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
