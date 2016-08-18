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

#define pii pair<int, int>
#define Graph vector<vector<pii>> 

#define F first
#define S second
#define undefined -1
#define INF 99999999

int V,E;
int start_v;

Graph adj_list;
vector<int> dist;
vector<int> prev_node;

void input(std::istream& pin) {
	pin >> V >> E;
	pin >> start_v;

	adj_list.resize(V);
	int r,c,cost;
	
	for(int i=0; i<E; i++) {
		scanf("%d %d %d", &r, &c, &cost);
		
		adj_list[r-1].push_back(make_pair(c-1, cost));	
	}	
}

class comp {
	public:
		bool operator() (pii a, pii b) {
			return a.S > b.S;
		}
};

void get_shortest_path_by_dijkstra(Graph& graph, int& source) {
	int u;
	priority_queue<pii, vector<pii>, greater<pii>> pri_Q;
	
	// set source distance to 0
	dist[source] = 0;

	pri_Q.push(make_pair(dist[source], source));
	
	while(!pri_Q.empty()) {
		//pick the top element
		u = pri_Q.top().S;
		pri_Q.pop();

		for(auto& it : graph[u]) {
			int	alt = dist[u] + it.S;
			if(alt < dist[it.F]) {
				dist[it.F] = alt;
				prev_node[it.F] = u;
				pri_Q.push(make_pair(dist[it.F], it.F));
			}	
		}
	}	

}

int main() {
	
	input(cin);

	dist.assign(V, INF);
	prev_node.assign(V, undefined);

	start_v--;
	get_shortest_path_by_dijkstra(adj_list, start_v);
	
	for(auto& it : dist) {
		if( it >= INF) printf("INF\n");
		else 
			printf("%d\n", it);	
	}

	return 0;
}
