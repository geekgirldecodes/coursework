#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using std::vector;
using std::string;

int edit_distance(const string &str1, const string &str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int> > distance(n + 1, vector<int>(m + 1, 0));

	for(int i = 0; i <= n; ++i) {
        distance[i][0] = i;
    }

    for(int i = 0; i <= m; ++i) {
        distance[0][i] = i;
    }

	int c = 0; //cost
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(str1[i-1] == str2[j-1])
				c = 0;
			else
				c = 1;
			distance[i][j] = std::min(std::min(distance[i-1][j],distance[i][j-1]) + 1, distance[i-1][j-1] + c);
		}
	}

	return distance[n][m];

  return 0;
}

void test(){
	string str1 = "short";
	string str2 = "ports";
	assert(3 == edit_distance(str1, str2));
	std::cout<< " Test 01 passed " << std::endl;

	string str3 = "ab";
	string str4 = "ab";
	assert(0 == edit_distance(str3, str4));
	std::cout<<" Test 02 passed "<< std::endl;
}

int main() {
  
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
