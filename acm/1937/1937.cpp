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

int n;
vector<vector<int>> bamboos;
vector<vector<int>> cache;

void input(std::istream& pin) {
	pin >> n;
	
	bamboos.assign(n, vector<int>(n));
	cache.assign(n, vector<int>(n));

	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			pin >> bamboos[i][j];
}

void init_cache(int& n) {
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			cache[i][j] = -1;
}

int bamboo_search(int x, int y) {

	if(cache[x][y] != -1) return cache[x][y];

	cache[x][y] = 1;
	
	//1. down
	if(x < n - 1 && bamboos[x+1][y] > bamboos[x][y]) 
		cache[x][y] = max(cache[x][y], 1 + bamboo_search(x+1, y));
	
	//2. up
	if(x > 0 && bamboos[x-1][y] > bamboos[x][y]) 
		cache[x][y] = max(cache[x][y], 1 + bamboo_search(x-1, y));
	
	//3. left
	if(y > 0 && bamboos[x][y-1] > bamboos[x][y]) 
		cache[x][y] = max(cache[x][y], 1 + bamboo_search(x, y-1));

	//4. right
	if(y < n - 1 && bamboos[x][y+1] > bamboos[x][y])
		cache[x][y] = max(cache[x][y], 1 + bamboo_search(x, y+1));	
	
	return cache[x][y];
}

int main() {
	input(cin);
	int ans = 0;

	init_cache(n);
	
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			ans = max(ans, bamboo_search(i, j));

	cout << ans << endl;

	return 0;
}
