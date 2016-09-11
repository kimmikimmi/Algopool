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

int n,k;
vector<int> coin_case;
int cache[10001];

void input(std::istream& pin) {
	pin >> n >> k;
	
	coin_case.assign(n, 0);	
	for(int i=0; i<n; i++)
		pin >> coin_case[i];
}

int recurcive_routine(int x) {
	if(x <=0) return 100001;
	if(cache[x] != 1000010) return cache[x];

	for(auto& it : coin_case) {
		if(cache[x] > recurcive_routine(x - it) + 1)
		   cache[x] = recurcive_routine(x - it) + 1;	
	}
	return cache[x];
}

int method(int i) {
	int ans = 0;
	for(auto& coin : coin_case) {
		if(coin <= k)
			cache[coin] = 1;
	}

	ans = recurcive_routine(i);

	return ans;
}

int main() {
	input(cin);
	for(int i=0; i<10001; i++) cache[i] = 1000010;
//	cout << cache[10000] ;
	cout << method(k) << endl;
	return 0;
}
