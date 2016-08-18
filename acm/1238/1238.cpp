#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <tuple>
#include <set>
#include <climits>

using namespace std;

#define INF INT_MAX - 10000000 // 정말 큰 수 !!

typedef vector<vector<int>> mat_t;

mat_t adj_mat;

int num_of_vertices; // 노드의 개수 
int num_of_edges; // adj_mat 에 들어갈 에지의 개수


int begin_v; //출발 지점
int end_v; // 도착 지점

inline void init_mat(int& n, mat_t& mat) {
	for(int i=0; i<n; i++)  
		for(int j=0; j<n; j++) { 
				mat[i][j] = INF;
				if(i==j) mat[i][j] = 0;
		}

}


void input(std::istream& pin) {
	scanf("%d %d %d", &num_of_vertices, &num_of_edges , &begin_v);

//	cout << num_of_vertices << " " << num_of_edges << " " << begin_v << endl;
	adj_mat.assign(num_of_vertices, vector<int>(num_of_vertices));
	init_mat(num_of_vertices, adj_mat);

	int start, dest, cost; // 1916.in 으로 부터 읽어오는 각 에지들...

	for(int i=0; i<num_of_edges; i++) {
		scanf("%d %d %d", &start, &dest, &cost);
		adj_mat[start-1][dest-1] = cost;
	}

}


int get_shortest_path_by_dijkstra(mat_t& mat, int& mat_size, int& source, int& dest) {
	vector<int> dist(mat_size, INF); // 벡터가 아니라 힙이어야 한다...

	vector<bool> visited(mat_size, false);
	//vector<int> S; // 현재 방문한 노드의 집합
	class prioritize{public: bool operator () (pair<int,int>& p1, pair<int,int>& p2){return p1.second > p2.second;}};
	priority_queue<pair<int, int>, vector<pair<int,int> >, prioritize > Q; 
	Q.push(make_pair(source-1, dist[source-1] = 0)); // 시작 지점에 대해 큐 에 삽입 .
	//방문하지 않은 노드들의 dist에 priority 를 준 min-heap;
//---------------------------------------------------------Initialized
	//while(false) {
	while(!Q.empty()) {
		// Q에서 거리값이 제일 작은 놈을 빼고, 뺀놈을 S에 넣는다. **성능의 핵심이다.
		pair<int, int> curr = Q.top();
		Q.pop();
		int curr_v = curr.first, curr_w = curr.second;
		if(visited[curr_v]) 
			continue;
		visited[curr_v]	= true;
		//아래의 for loop 에서 adj_mat 대신에 adj_list로 구현할 경우 속도가 빨라진다.
		for(int i=0; i<mat[curr_v].size(); i++)
			if(!visited[i] && mat[curr_v][i] + curr_w < dist[i]) 
				Q.push(make_pair(i, dist[i] = mat[curr_v][i] + curr_w));
	}
	
	return dist[dest-1];
}

int main() {
	input(cin);
	/*
	for(int i=0; i<num_of_vertices; i++) { 
		for(int j=0; j<num_of_vertices; j++) {
			if(adj_mat[i][j] == INF) cout << "INF\t";
			else 
				cout << adj_mat[i][j] << "\t";

		}
		cout << endl;
	}*/
	//cout << "Source = " << begin_v << endl;
	int maximum = 0;
	for(int i=0; i<num_of_vertices; i++) {
		int dest = i+1;
		//cout << get_shortest_path_by_dijkstra(adj_mat, num_of_vertices, dest, begin_v) << " + "  
		//	<< get_shortest_path_by_dijkstra(adj_mat, num_of_vertices, begin_v, dest) << endl; 
	
		 int tmp = get_shortest_path_by_dijkstra(adj_mat, num_of_vertices, dest, begin_v) +
			 get_shortest_path_by_dijkstra(adj_mat, num_of_vertices, begin_v, dest); 
		 if(tmp > maximum) maximum = tmp; 
	}
	cout << maximum;
	return 0;
}
