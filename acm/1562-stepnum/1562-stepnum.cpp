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
#define mod 1000000000

int N;
long long  cache[10][100][1024] = {0};


void input(std::istream& pin) {
	pin >> N;
}




int method(int i, int len, int bit) {
	
	if(i == 10 || i == -1) return 0;

	

	if(len == 1) {
		
		return cache[i][len][bit] = 1;
	}

	if(cache[i][len][bit] != 0) return cache[i][len][bit];

	 cache[i][len][bit] = method(i-1, len-1, bit|(1 << i))%mod + method(i+1, len-1, bit|(1<<i))%mod;
	 cache[i][len][bit] %= mod;
	 return cache[i][len][bit];
}

int main() {
	int tmp;
	input(cin);
	int sum = 0;
	
	for(int i=1; i<10; i++) {
		// cout << sum << endl;
		cout <<	method(i,N,0) << endl;	
	
	}

	for(int i=0; i<10; i++) {
		for(int j=0; j<N; j++) {
			cout << cache[i][j][1] << " ";
		}
		cout << endl;
	}


	return 0;
}


