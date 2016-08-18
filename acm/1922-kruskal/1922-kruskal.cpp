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

struct edge {
	int src;
	int dest;
	int weight;
};

int N; // # of nodes
int M; // # of edges

vector<edge> edges;
vector<vector<bool>> bit_matrix;
vector<vector<bool>> bit_map;

void input(std::istream& pin) {
	pin >> N >> M;
	edge e;
	edges.assign(M, e);
	bit_matrix.assign(N, vector<bool>(N));	
	bit_map.assign(N, vector<bool>(N));
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			bit_matrix[i][j] = false;
			bit_map[i][j] = false;
		}
	}
	for(int i=0; i<M; i++) {
		scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
		bit_matrix[edges[i].src-1][edges[i].dest-1] = true;
		bit_matrix[edges[i].dest-1][edges[i].src-1] = true;
	}
}

void display() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << bit_matrix[i][j] << " ";
		}
		cout << endl;
	}
}


//
// function to detect a cycle including v
// using BFS
bool detected_cycle_with(edge& e) {
	queue<int> q;
	int dest = e.dest-1;
	int src = e.src-1;

	vector<bool> visited(N, false);
	
	q.push(src);
	visited[src] = true;
	
	while(!q.empty()) {
		int q_top = q.front();
		q.pop();
		//cout << "top = " << q_top << endl;
		for(int i=0; i<N; i++) {
			if(bit_matrix[q_top][i] && bit_map[q_top][i]) { 
				if(!visited[i]) { 
					if(q_top != src && i == dest) return true; 
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}	
	return false;
}


int method() {
	int min_cost = 0;
	int edge_cnt = 0;
	sort(edges.begin(), edges.end(), [](edge e1, edge e2) {
		return e1.weight < e2.weight;});
	
	for(int i=0; i<M; i++) {
		// a cycle detected...
		if(detected_cycle_with(edges[i])) {
	//		cout << "there is a cycle while inserting" << edges[i].src -1 << "to "  << edges[i].dest-1 <<   endl;
			continue;
		}

		bit_map[edges[i].src-1][edges[i].dest-1] = true;
		bit_map[edges[i].dest-1][edges[i].src-1] = true;
		min_cost += edges[i].weight;
		edge_cnt++;	
		if(edge_cnt == N-1) return min_cost;
		//cout << edges[i].src-1 << "-> " << edges[i].dest-1  << " " << min_cost<< endl;
	}

	return min_cost;
}

int main() {
	input(cin);
	//display();
	cout << method();
	return 0;
}
