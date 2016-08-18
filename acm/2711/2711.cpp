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
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int loc = 0;
		string tmp_str;
		cin >> loc >> tmp_str;
		tmp_str.erase(loc-1, 1);
		cout << tmp_str << endl;
	}
	return 0;
}
