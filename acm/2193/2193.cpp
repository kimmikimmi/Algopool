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
int N;
vector<unsigned long long> cache;

void input(std::istream& pin) {
	pin >> N;
	cache.assign(N+1, -1);
}

unsigned long long method(int i) {
	if(cache[i] != -1) return cache[i];

	if(i <= 2) return 1;
	
	cache[i] = method(i-1) + method(i-2);
	return cache[i];
}

int main() {
	input(cin);
	cout << method(N);

	return 0;
}
