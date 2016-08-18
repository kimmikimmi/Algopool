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

int N,M;
vector<vector<char>> mat;
void input(std::istream& pin) {
	pin >> N >> M;
	
	mat.assign(N, vector<char>(M));
	for(int i=0; i<N; i++) 
		for(int j=0; j<M; j++) {
			pin >> mat[i][M-j-1];
		}
}	


int main() {
	input(cin);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	return 0;
}
