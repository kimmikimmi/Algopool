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

//vector<bool> self_nums;

bool self_nums[10001];
int d(int n) {
	int x = 0;
	string n_str = to_string(n);
	x = n;
	for(auto& it : n_str) {
		x += it - '0';
	}
	return x;
}


int main() {
//	self_nums.assign(10010, true);
	for(int i=1; i<10001; i++) {
		int tmp = i;
		if(self_nums[i]) continue;
		while(i < 10001) {
			self_nums[d(i)] = true;
			i = d(i);
			
		}	

		i = tmp + 1;
	}

	for(int i=1; i<10001; i++) {
		if(!self_nums[i]) cout << i << endl;
	}
	return 0;
}
