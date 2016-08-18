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
typedef vector<vector<int>> mat_t;

void input(std::istream& pin) {
	int tmp;
	int max_val = 0; int r = 0; int c = 0;
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			pin >> tmp;
			if(tmp > max_val ) {
				max_val = tmp;
				r = i; c = j;
			}
		}
	}
	cout << max_val << endl << r+1 << " " << c +1<< endl;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	return 0;
}
