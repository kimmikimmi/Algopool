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
vector<string> strings;


void input(std::istream& pin) {
	pin >> T;
	string tmp_str;
	for(int i=0; i<T; i++) {
		pin >> tmp_str;
		strings.push_back(tmp_str);
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	for(auto& it : strings) {
		cout << it[0] << it[it.size()-1] << endl;
	}
	return 0;
}
