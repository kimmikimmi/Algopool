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


int T;

vector<pair<int, int>> pairs;

void input(std::istream& pin) {
	pin >> T;
	string str;
	for(int i=0; i<T; i++) {
		pin >> str;
		pair<int, int> p(str[0]-'0', str[2]-'0');
		pairs.push_back(p);
	}
}

int add(pair<int, int> p) {
	return p.first + p.second;
}

int main() {
	input(cin);
	for(auto& it : pairs)
		cout << add(it) << endl;
	return 0;
}
