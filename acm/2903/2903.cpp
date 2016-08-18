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
vector<int> cache;
void input(std::istream& pin) {
	pin >> N;
	cache.assign(N+1, -1);
}

int method(int i) {
	if(cache[i] != -1) return cache[i];
	if(i == 1) return 9;
	if(i == 2) return 25;

	return cache[i] = (int)pow(2*sqrt(method(i-1)) -1, 2);
}

int main() {
	input(cin);
	cout << method(N);
	return 0;
}
