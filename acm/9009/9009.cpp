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

vector<int> candidates;
vector<int> cache;
int T;

void input(std::istream& pin) {
	pin >> T;
	candidates.assign(T, -1);
	for(int i=0; i<T; i++) 	
		pin >> candidates[i];
}

int fibo(int n) {
	if(cache[n] != -1) return cache[n];
	if(n == 0) return 0;
	if(n == 1) return 1;

	return cache[n] = fibo(n-1) + fibo(n-2);
}

int main() {
	input(cin);
	cache.assign(45, -1);
	cache[0] = 0;
	cache[1] = 1;	
	fibo(44);
	
	sort(cache.rbegin(), cache.rend());
	
	for(auto& candidate : candidates) {
		int val = candidate;
		vector<int> ans;
		for(auto& it : cache) {
			if(val == 0) break;
			if(val >= it) {
				val -= it;
				ans.push_back(it);
			}
		}
		sort(ans.begin(), ans.end());
		for(auto& it : ans) cout << it << " ";
		cout << endl;
	}


	return 0;
}
