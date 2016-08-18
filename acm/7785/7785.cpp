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

int n;
map<string, bool, greater<string> > commute_log;

void input(std::istream& pin) {
	pin >> n;
	string name, c_log;
	for(int i=0; i<n; i++) {
		pin >> name >> c_log;
		if(c_log == "enter")
			commute_log[name] = true;
		else
			commute_log[name] = false;

	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	for(auto& it : commute_log) 
		if(it.second) cout << it.first  << endl;
	return 0;
}
