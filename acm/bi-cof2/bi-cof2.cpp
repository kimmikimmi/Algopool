#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

long long int cache[1001][1001];
int first;
int second;
long long int combination(int n, int r) {

	if(cache[n][r] != -1) return cache[n][r];
	
	if(r == 0 || n == r) {
		cache[n][r] = 1; 
		return 1;
	}
	cache[n][r] = combination(n-1, r)%10007 + combination(n-1,r-1)%10007;

	return cache[n][r];
}

void setUpDynamic() {
	for(int i=0; i<1001; i++) {
		for(int j=0; j<1001; j++) {
			cache[i][j] = -1;
		}
	} 
}

void input(istream& in) {
	in >> first >> second;
}

void method() {
	setUpDynamic();
	cout << combination(first, second) % 10007;
}


int main(int argc, char const *argv[])
{
	
	input(cin);
	method();
	
	return 0;
}
