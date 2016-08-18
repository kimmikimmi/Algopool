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

vector<int> cache;
int N;
vector<int> A;

void input(std::istream& pin) {
	pin >> N;
	A.assign(N,0);
	cache.assign(N,-1);
	for(int i=0; i<N; i++) {
		pin >> A[i];

	}
	cache[0] = 0;
}

int method(int x) {
	if(x == 0 ) return cache[0];
	int min_step = 1001;	
	for(int i=0; i<x; i++) {
		if(i + A[i] >= x) {
			if(min_step > cache[i] + 1) min_step = cache[i] + 1;
		}
	}
	if(min_step == 1001) cache[x] = -1;
	else 
		cache[x] = min_step;
	return cache[x];
}

int main() {
	input(cin);
	for(int i=0; i<N; i++) 
		method(i);
	cout << cache[N-1];
	return 0;
}
