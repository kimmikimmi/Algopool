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

long long int_map[10] = {0};
string input_str;

void input(std::istream& pin) {
	pin >> input_str;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	
	//O(N)
	for(auto& it : input_str) {
		int_map[it-'0']++;
	}
	
	//
	for(int i=9; i>=0; i--) {
		for(int j=0; j<int_map[i]; j++) printf("%d", i);
	}
	return 0;
}
