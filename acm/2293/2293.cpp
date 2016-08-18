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

vector<int> coin_case;
vector<int> cache;

int n,k;

void input(std::istream& pin) {
	pin >> n >> k;
	
	coin_case.assign(n, -1);
	cache.assign(k+1,-1);

	for(int i=0; i<n; i++)  
		pin >> coin_case[i];
}

int method(int i) {
	//cout << "method " << i << endl;
	if(find(coin_case.begin(), coin_case.end(), i) != coin_case.end()) {
//		cout << i << endl;	
		return 1;
	}
	
	if(cache[i] != -1) return cache[i];

	for(auto& it : coin_case) { 
		if( i - it > 0) { 
			cache[i] += method(i - it);  
		}
	}

	return cache[i];
}


int main() {

	input(cin);
	
	cout << method(k);

	return 0;
}




