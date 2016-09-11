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
vector<int> testcases;
vector<int> cache_a;
vector<int> cache_b;
vector<int> cache_c;
vector<int> cache_d;


void init_cache(int cap) {
	cache_a.clear();
	cache_b.clear();
	cache_c.clear();
	cache_d.clear();
	cache_a.assign(cap+1, -1);
	cache_b.assign(cap+1, -1);
	cache_c.assign(cap+1, -1);
	cache_d.assign(cap+1, -1);
}

void input(std::istream& pin) {
	pin >> N;
	int buf;
	for(int i=0; i<N; i++) {
		pin >> buf;
		testcases.push_back(buf);
	}
}
int A(int i);
int B(int i);
int C(int i);
int D(int i);

int A(int i) {
	if(i<=1) return 0;
	if(i==2) return 1;
	else {
		if(cache_a[i] != -1) return cache_a[i];
		cache_a[i] = A(i-2) + B(i-2) + C(i-2) + D(i-2);
		return cache_a[i];
	}
}

int B(int i) {
	if(i <= 1) return 0;
	if(i == 2) return 1;
	else {
		if(cache_b[i] != -1) return cache_b[i];
		cache_b[i] = A(i) + B(i-2);
		return cache_b[i];
	}
}

int C(int i) {
	if(i <= 1) return 0;
	if(i == 2) return 2;
	else {
		if(cache_c[i] != -1) return cache_c[i];
		cache_c[i] = C(i-1) + 2*A(i);
		return cache_c[i];
	}
}

int D(int i) {
	if( i == 0) return 0;
	if( i == 1) return 1;
	if( i == 2) return 1;
	else {
		if(cache_d[i] != -1) return cache_d[i];
		cache_d[i] = A(i-1) + B(i-1) + C(i-1) + D(i-1); 
		return cache_d[i];
	}
}

int main() {
	input(cin);
	for(auto& it : testcases) {
	init_cache(it);	
	int sum = A(it) + B(it) + C(it) + D(it) ;
	cout << sum << endl;
	}
	return 0;
}
