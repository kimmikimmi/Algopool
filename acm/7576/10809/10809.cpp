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

string word;
vector<int> bit_map(26,-1);
void input(std::istream& pin) {
	pin >> word;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	int i = 0;
	for(auto& it : word) {
		if(bit_map[it - 'a'] == -1) bit_map[it-'a'] = i;
		i++;	
	}
	for(auto& it : bit_map) 
		cout << it << " ";
	return 0;
}
