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

#define UNDEFINED -1


int N,M;

vector<vector<int>> graph;
vector<int> parents;
vector<int> level;
vector<bool> visited;

void init_vecs(int& size_vec) {

	graph.resize(N+1);
	parents.assign(N+1, UNDEFINED);
	level.assign(N+1, UNDEFINED);
	visited.assign(N+1, false);
}

void input(std::istream& pin) {

	pin >> N ;
	init_vecs(N);

	int v1,v2;
	for(int i=0; i<N-1; i++) {
		pin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}	

}
void dfs(int here, int d) {
	visited[here] = true;
	level[here] = d;

	int there;
	for(int i=0; i<graph[here].size(); i++) {
		there = graph[here][i];

		if(!visited[there]) {
			dfs(there, d+1);
			parents[there] = here; // 각 노드들의 부모를 저장 
		}	
	}
}
int method() {
	return 0;
}

int main() {
	input(cin);
	dfs(1, 1);
	cin >> M;
	int v1, v2;
	for(int i=0; i<M; i++) {
		int tmp1,tmp2;
		cin >> v1 >> v2;
		tmp1 = v1; tmp2 = v2;
		if(level[v1] < level[v2]) swap(v1,v2);
//		cout << v1 <<"    " << v2 << endl;
		// a를 올리자 !
		while(!(level[v1] == level[v2])) {
			v1 = parents[v1];
		}

		while(!(v1==v2)) {
			v1 = parents[v1];
			v2 = parents[v2];
		}
		int sol = 
		cout << v1 << endl;
	}

	return 0;
}
