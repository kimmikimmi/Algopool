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
		int tmp; string tmp_str;
		cin >> tmp >> tmp_str;
		for(auto& it : tmp_str) {
			for(int i=0; i<tmp; i++) {
				cout << it;
			}
		}
		cout << endl;
	}
	return 0;
}
