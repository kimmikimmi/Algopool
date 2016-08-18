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


vector<int> odds;
void input(std::istream& pin) {
	int tmp;
	for(int i=0; i<7; i++) {
		pin >> tmp;
		if(tmp%2 == 1) odds.push_back(tmp);
	}
}

int method() {
	if(odds.empty()) {
		cout << -1 << endl;
		return 0;
	}
	sort(odds.begin(), odds.end());
	int sum  = 0;
	for(auto& it : odds) {
		sum += it;
	}
	cout << sum << endl << odds[0];

	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
