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
	int a;
	cin >> t;
	for(int i=0; i<t; i++) {
		vector<int> bag;
		for(int j=0; j<5; j++) {
			cin >> a ;
			bag.push_back(a);
		}
		sort(bag.begin(), bag.end());
		if(bag[3] - bag[1] >= 4) cout << "KIN" << endl;
		else {
			int sum = 0;
			for(int j=1; j<4; j++) 
				sum += bag[j];
			cout << sum << endl;	
		}
	}

	return 0;
}
