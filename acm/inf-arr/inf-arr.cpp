#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;


long long int N;
long long int P;
long long int Q;


long long int cache[10000000];

void input(istream& in) {
	in >> N >> P >> Q;


	cache[0] = 1;
	cache[1] = 2;
}

long long int method(long long int i) {
		

	if(i == 0) return cache[0];
	if(i == 1) return cache[1];
	
	if(i >= 10000000) {
		return method(i/P) + method(i/Q);
	} else {
		if(cache[i] != 0) return cache[i];
		return cache[i] = method(i/P) + method(i/Q);
	}
	
}

int main() {
	input(cin);

	// cout << N << "  " << P << " " << Q  << endl;
	
	 cout << method(N) << endl;
	
	 // for(auto v : cache) {
	 // 	if(v == 0) break;

	 // 	cout << "v = " <<  v << endl;
	 // }
	return 0;
}
