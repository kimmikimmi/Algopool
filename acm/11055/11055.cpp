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
vector<int> seq;
vector<int> cache;
void input(std::istream& pin) {
	pin >> N;
	seq.resize(N);
	cache.assign(N, -1);

	for(int i=0; i<N; i++) 
		pin >> seq[i];
}

int method() {
	int max_val = 0;
	cache[0] = seq[0];
	for(int i=0; i<N; i++) {
		cache[i] = seq[i];
		for(int j=i; j<N; ++j) {
			if(seq[j] > seq[i]) { 
				cache[j] = max(cache[i] + seq[j], cache[j]);
				//cout << "seq[j] = " << seq[j] << " , seq[i] = " << seq[i] << 
				//	"cache[j] = " << cache[j] << "cache[i] = " << cache[i] << endl; 
			}
		}
	}
	

//	for(int i=0; i<N; i++) cout << cache[i] << endl; 
		for(auto& it : cache) if(max_val < it) max_val = it; 
	
		
	
	return max_val;
}


int main() {
	input(cin);
	cout << method();
	return 0;
}
