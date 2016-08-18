#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <tuple>
#include <set>
#include <bitset>
using namespace std;

long long N;
void input(std::istream& pin) {
	pin >> N;
}


long long fromBin(string bin) {
	int i=0;
	int size = bin.size();
	long long sum = 0;
	for(auto iter = bin.rbegin(); iter != bin.rend(); ++iter) {
		if(*iter == '1') sum += (int)pow(2, i); 

		i++;
	}	
	return sum;
}

int main() {
	input(cin);
	string binary_num = "";
	string b_num = std::bitset<30>(N).to_string();
	for(auto it = b_num.begin(); it != b_num.end(); ++it) {
		if( *it== '1') {
			binary_num.append(it,b_num.end());
			break;
		}	
	}
	 reverse(binary_num.begin(), binary_num.end());

//	cout << b_num << " " << binary_num << endl;
	cout << fromBin(binary_num);
	return 0;

}
