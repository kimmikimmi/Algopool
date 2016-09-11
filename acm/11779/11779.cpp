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
int start_v, dest_v;

Graph adj_list;
vector<int> dist;
vector<int> prev_node;

void input(std::istream& pin) {
	pin >> V;
	pin >> E;
	adj_list.resize(V);
	int r,c,cost;
	
	for(int i=0; i<E; i++) {
		scanf("%d %d %d", &r, &c, &cost);
		
		adj_list[r-1].push_back(make_pair(c-1, cost));	
	}	
	
	pin >> start_v >> dest_v;
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
	prev_node[source] = -1;
	pri_Q.push(make_pair(dist[source], source));
	
	while(!pri_Q.empty()) {
		//pick the top element
		u = pri_Q.top().S;
		pri_Q.pop();

		for(auto& it : graph[u]) {
			int	alt = dist[u] + it.S;
			if(alt <= dist[it.F]) {
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

	cout << dist[dest_v-1] << endl;
	int visited_cities = 0;
	int curr = dest_v-1;
	vector<int> cities;
	while(curr != -1) {
		cities.push_back(curr+1);
		visited_cities++;
		curr = prev_node[curr];
	}	
	cout << visited_cities << endl;
	for(auto it = cities.rbegin(); it != cities.rend(); ++it) 
		cout << *it << " ";
	return 0;
}
