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

#define MOD 9901

int N;
vector<int> cache;


void input(std::istream& pin) {
	pin >> N;
	cache.assign(N+1, -1);
}

int method(int i) {
	if(i==0) return 1;
	if(i==1) return 3;
	if(cache[i] != -1) return cache[i];
	return cache[i] = ((method(i-1)*2)%MOD + method(i-2)%MOD)%MOD;
}

int main() {
	input(cin);
	cout << method(N);
	return 0;
}
