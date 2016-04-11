#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num;
vector<int> cache;
#define BIASED (10007)
void input(istream& in) {
	in >> num;
	cache.resize(num+1);
	
}

int method(int n) {
	if(cache[n] != 0) return cache[n];

	if(n == 1) {
		cache[1] = 1;
		return cache[n];
	}
	if(n == 2) {
		cache[2] = 3;
		return cache[2];
	}
	return cache[n] = method(n-1)%BIASED  + method(n-2)*2%BIASED;
}

int main() {
	input(cin);
	cout << method(num)%BIASED << endl;

	return 0;
}
