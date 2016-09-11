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
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> graph;

void input(std::istream& pin) {
	pin >> N >> M >> V;
	
	graph.resize(N+1);
	for(int i=0; i<M; i++) {
		int a,b;
		pin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

}
void iterate(int& start, vector<bool>& v) {
	printf("%d ", start);
	v[start] = true;
	for(auto& it : graph[start]) {
		if(!v[it]) iterate(it, v);
	}
}

void DFS_search(int start) {
	vector<bool> visited(N+1, false);

	iterate(start, visited);
}

void BFS_search(int start, vector<vector<int>>& g) {
	queue<int> q;
	q.push(start);
	vector<bool> visit(N+1, false);	

	while(!q.empty()) {
		int s = q.front();
		q.pop();
		if(!visit[s])printf("%d ", s);
		visit[s] = true;

		for(auto& it : g[s]) {
			if(!visit[it]) q.push(it);
		}
	}
}

int main() {

	input(cin);
	for(int i=1; i<=N; i++) 
		sort(graph[i].begin(), graph[i].end());
	
	DFS_search(V);
	cout << endl;
	BFS_search(V, graph);
	return 0;
}
