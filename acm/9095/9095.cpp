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

vector<int> int_bag;
vector<int> cache;
int T;

void input(std::istream& pin) {
	pin >> T;
	int elem;
	cache.assign(12,-1);
	for(int i=0; i<T; i++) {
		pin >> elem;
		int_bag.push_back(elem);
	}
}

int method(int n) {
	if(cache[n] != -1) return cache[n];
	
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 4;
	cache[n] = method(n-1) + method(n-2) + method(n-3);
	return cache[n];
}

int main() {
	input(cin);
	for(auto& it : int_bag) 
		cout << method(it) << endl;

	return 0;
}
