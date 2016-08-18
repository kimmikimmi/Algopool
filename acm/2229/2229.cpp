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
vector<int> scores;

void input(std::istream& pin) {
	pin >> N;
	scores.assign(N, 0);
	cache.assign(N+1,-1);
	for(int i=0; i<N; i++) 
		pin >> scores[i];
}

int make_dif(int x, int y) {
	int min_val = 10001;
	int max_val = -1;

	for(int i=x; i<=y; i++) {
		if(scores[i] > max_val)  max_val = scores[i];
		if(scores[i] < min_val) min_val = scores[i];
	}
	
	return max_val - min_val;
}

int method(int nth) {
	if(nth <= 0) return 0;
	if(cache[nth] != -1) return cache[nth];
	if(nth ==1) return (int)abs(scores[1] - scores[0]);

	for(int i=nth; i>=0; i--) {
		int dif = make_dif(i,nth);
		if(method(i-1) +  dif > cache[nth]) {
			cache[nth] = method(i-1) + dif;
		}
	}	
	
	return cache[nth];
}

int main() {
	input(cin);
	cout << method(N-1);
	return 0;
}
