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
vector<int> box;
vector<int> cache;
void input(std::istream& pin) {
	pin >> n;
	box.assign(n, 0);
	cache.assign(n, -1);

	for(int i=0; i<n; i++) 
		pin >> box[i];
}

int method() {
	for(int i=0; i<n; i++) {
		cache[i] = 1;
		for(int j=0; j<i; j++) {
			if(box[i] > box[j]) 
				cache[i] = max(cache[j] + 1, cache[i]);
		}
	}
	int max_val = 0;
	for(auto& it : cache) if(max_val < it) max_val = it;
	return max_val;
}

int main() {
	input(cin);
	cout << method();
	return 0;
}
