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
int m;

vector<vector<bool>> adj_mat;
vector<bool> bit_map;

void input(std::istream& pin) {
	pin >> n;
	pin >> m;
	bit_map.assign(n+1, false);
	adj_mat.assign(n+1, vector<bool>(n+1));
	int a,b;
	for(int i=0; i<m; i++) {
		pin >> a >> b;
		adj_mat[a][b] = true;
		adj_mat[b][a] = true;	
	}	
}

int method() {
	return 0;
}

int main() {
	input(cin);
	int cnt = 0;
	for(int i=2; i<n+1; i++) {
		if(adj_mat[1][i]) {
			bit_map[i] = true;
			for(int j=2; j<n+1; j++) {
				if(adj_mat[i][j]) 
					bit_map[j] = true;
			}	
		}	
	}
	for(auto it : bit_map) {
		if(it) cnt++;
	}	
	cout << cnt << endl;
	return 0;
}
