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
#include <cctype>

using namespace std;

int N;

vector<string> panagrams;
map<char, int> fringe;

void input(std::istream& pin) {
	pin >> N;
	string tmp_str;
	for(int i=0; i<N; i++) {
		pin >> tmp_str;
		panagrams.push_back(tmp_str);
	}
}

void init_fringe() {
	for(int i=0; i<N; i++) {
		fringe['a'+i] = 0;
	}
}

int method(string str) {
	string trans_str = "";
	for(auto& it : str) {
		trans_str += toupper(it);
	}
	cout << trans_str << endl;
	return 0;
}

int main() {
	input(cin);
	init_fringe();
	for(auto& it : panagrams) cout << it << endl;
	method(panagrams[0]);

	return 0;
}
