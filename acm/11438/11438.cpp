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

#define NCNT 100000
#define LGN 20

int n, dy[NCNT+1][LGN+1], lv[NCNT+1];
bool visit[NCNT+1];
vector<int> g[NCNT+1];



void dfs(int node) {
	visit[node] = true;
	for(int i=0; i<g[node].size(); i++) {
		int u = g[node][i];
		if(!visit[u]) {
			lv[u] = lv[node] +1;
			dy[u][0] = node;
			for(int j=1; j<LGN; j++) 
				dy[u][j] = dy[dy[u][j-1]][j-1];
			dfs(u);
		}
	}
}


int lca(int a, int b) {
	if(lv[a] < lv[b]) swap(a, b);

	for(int i=LGN; i>=0; i--) 
		if( (1 << i) <= lv[a] - lv[b] ) 
			a = dy[a][i];

	if( a==b) return a;

	for(int i=LGN; i>=0; i--) 
		if(dy[a][i] != dy[b][i] ) 
			a = dy[a][i], b = dy[b][i];
	return dy[a][0];
}

int main() {
	int m,a,b;
	cin >> n;
	for(int i=1; i<n; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	lv[1] = 1;
	dfs(1);
	cin >> m;
	while(m--) {
		cin >> a >> b;
		cout << lca(a,b) << endl;
	}
	return 0;
}
