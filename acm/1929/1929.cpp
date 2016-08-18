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

int M,N;

vector<bool> prime_sieve;

void input(std::istream& pin) {
	pin >> M >> N;
	prime_sieve.assign(N+1, true);
	prime_sieve[0] = false;
	prime_sieve[1] = false;
}

int method() {
	for(int i=2; i<N+1; i++) {
		int k = 1;

		if(!prime_sieve[i]) continue;
		while(true) {
			k++;
			if(i*k > N) break;
			prime_sieve[i*k] = false;
			
		}
	}
	return 0;
}

int main() {
	input(cin);
	method();
	for(int i=M; i<N+1; i++) if(prime_sieve[i]) printf("%d\n",  i);
	return 0;
}
