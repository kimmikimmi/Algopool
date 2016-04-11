#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<std::vector<int>> mat;
vector<std::vector<int>> cache;
int r,c;
void input(istream& in) {
	
	int temp;
	in >> r >> c;
	mat.resize(r);
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			in >> temp;
			mat[i].push_back(temp);
		}
	}
}

void init_table() {
	cache = mat;
	copy(mat.begin(), mat.end(), cache.begin());

	for(int i=1; i<c; i++) 
		cache[0][i] = cache[0][i-1] + cache[0][i];
	for(int i=1; i<r; i++)	
		cache[i][0] = cache[i-1][0] + cache[i][0];
}

int method(int r, int c) {
	
	for(int i=1; i<r; i++) {
		for(int j=1; j<c; j++) {
			cache[i][j] = 
				max({cache[i-1][j-1], cache[i-1][j], cache[i][j-1]}) 
				+ cache[i][j];
		}
	}
	return cache[r-1][c-1];
}

int main() {
	input(cin);
	init_table(); 
	 cout << method(r, c) << endl;
	return 0;
}
