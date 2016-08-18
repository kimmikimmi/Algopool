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
vector<string> par_strs;

void input(std::istream& pin) {
	pin >> T;
	string tmp_buf;
	for(int i=0; i<T; i++) {
	   pin >> tmp_buf;
	   par_strs.push_back(tmp_buf);
	}
}

bool method(string fuck_off) {
	stack<char> kim_stack;

	for(auto& it : fuck_off) {
		if(kim_stack.empty() && it == ')') return false;
		if(it == '(')
			kim_stack.push(it);
		else
			kim_stack.pop();
	}
	if(!kim_stack.empty()) return false;

	return true;
}

int main() {
	input(cin);
	for(auto& it : par_strs) {
		if(method(it)) cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
