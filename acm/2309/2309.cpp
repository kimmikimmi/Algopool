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
vector<int> dwarves;
void input(std::istream& pin) {
	dwarves.assign(9, 0);
	for(int i=0; i<9; i++) {
		int tmp = 0;
		pin >> tmp;
		dwarves[i] = tmp;
	}
}

int method() {
	int sum = 0;
	for(auto& it : dwarves) {
		sum += it;
	}
	int t1, t2;
	int tricks = sum - 100;
	for(int i=0; i<8; i++) {
		for(int j=i+1; j<9; j++) {
			if(dwarves[i] + dwarves[j] == tricks) {
				t1 = dwarves[i]; t2 = dwarves[j];
			}
		}
	}
	sort(dwarves.begin(), dwarves.end());
	for(auto& it : dwarves) {
		if(it == t1 || it == t2) continue;
		else
			cout << it << endl;
	}
					
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
