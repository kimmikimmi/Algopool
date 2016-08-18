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


/*
 * Writed and Created by Hyeonjun
 * .cpp
 * Bellman fold algorithm.
 * O(VE) it's relatively slawer than Dijkstra shortest path alroghthm.
 * but this algorithm doesn't care |E| < 0.
 * but If there is a cycle, the path is less than 0.
 * this algorithm is not going to work!.
 *
 */
using namespace std;

typedef struct {
	int source;
	int dest;
	int weight;
} Edge;

int N,M; // N = # of vertices , M = # of edges 
vector<int> distances;
vector<Edge> edges;
/*
 * as a data structure gonna be used, which one is better ? adjacent matrix or adjacentlist
 */

#define INF ((1 <<  (sizeof(int)*8-2))-1)

void init_distance(int n, int source) {
	
	distances.assign(n, INF);
	distances[source] = 0;

}

void input(std::istream& pin) {
	
	pin >> N >> M;
	Edge e;
	edges.assign(M, e);
	int tmp_src, tmp_dest, tmp_weight;
	for(int i=0; i<M; i++) {
		pin >> tmp_src >> tmp_dest >> tmp_weight;
		edges[i].source = tmp_src-1;
		edges[i].dest = tmp_dest-1;
		edges[i].weight = tmp_weight;
	}

}

int get_shortest_path_by_bellmanFord() {

	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(distances[edges[j].dest] > distances[edges[j].source] + edges[j].weight) 
				distances[edges[j].dest] = distances[edges[j].source] + edges[j].weight;
		}
	}
	
	// handling exception! negative cycle.
	for(int i=0; i< M; i++) {
		if(distances[edges[i].dest] > distances[edges[i].source] + edges[i].weight) {
			//cout << "Error occured. Negative edge weight cycles detected" << endl;
			cout << -1 << endl;
			return 0;		
			break;
			
		}
	}
	
	for(int i=1; i<N; i++) {
		//cout << "The shortest distance between node " << 0 << " and " << i << " is " 
		  if(distances[i] >= INF)
			 cout << -1 << endl;
		  else 
			  cout  << distances[i] << endl;	
	}

	return 0;
}

int main() {
	input(cin);
	init_distance(N, 0);
	//cout << N << " " << M << endl;
	//for(auto& it : edges) cout << it.weight << endl;
	get_shortest_path_by_bellmanFord();

	return 0;
}
