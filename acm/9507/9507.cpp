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
int t;
vector<int> cases;
vector<long long> cache;
void input(std::istream& pin) {
	pin >> t;
	cases.assign(t, 0);
	cache.assign(68, -1);
	for(int i=0; i<t; i++) {
		pin >> cases[i]; 
	}
}

long long method(int n) {
	if(cache[n] != -1) return cache[n];
	if(n < 2) return 1;
	if(n == 2) return 2;
	if(n == 3) return 4;
	
	return cache[n] = method(n-1) + method(n-2) + method(n-3) + method(n-4);
}

int main() {
	input(cin);
	for(auto it : cases) 
		cout << method(it) << endl;
	return 0;
}
