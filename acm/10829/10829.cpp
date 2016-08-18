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

using namespace std;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	long long N;
	cin >>N;
	cout << N << endl;

	string b_num = std::bitset<30>(N).to_string();
	string binary = "";
	//cout << b_num << endl;

	for(auto i=0; i<b_num.size(); i++) {
		if(b_num[i] == '1') {
			binary = b_num.substr(i, b_num.size()-i);
			break;
		}
	}
	cout << binary << endl;
	return 0;

}
