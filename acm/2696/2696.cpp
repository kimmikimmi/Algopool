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
 *
 *Floyd-Warshall algorithm

 *Time complexity : O(|V|^3)
 
 *the algorithm to find all the paths of every vertex
 
 *It usually is compared to Dijkstra algorithm, It seems quite important to choose right algorithm 
	depends on the situation.
 *
 * algorithm is based on Dynamic programming. it gets all the minimum cost of the paths for all two vertices

 * 1) 두 점을 잇는 최소 비용 경유지를 거치거나 거치지 않는 경로 중 하나에 속한다.
 * 2) 만약 경유지를 거친다면 그것을 이루는 부분 경로 역시 최소 비용 경로여야 한다.
 *
 * -> 이는 중첩된 부분문제로 볼 수 있으며 동적 계획법을 적용하여 효과적으로 접근할 수 있다. 한편 비용을 구하는 김에
 *  , 어떤 경유지를 지나서 최소 비용을 만들었는지 기록해두면 최소 비용 뿐만 아니라 최소 비용 경로까지도 구할 수 있다.
 
 */
using namespace std;

typedef vector<vector<int>> mat_t;
#define INF 10000000

int N, M; // N = # of vertices, M = # of edges
mat_t adj_mat; // adjacent matrix to implement graph
mat_t via; // the matrix from i to j  to store the latest via



/*this initialsing function 
 * assign new matrix i==j -> 0 , ,i!=j -> INF 
 */
void init_mat(mat_t& matrix, int& r, int& c) {
	matrix.assign(r, vector<int>(c));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(i==j) matrix[i][j] = 0;
			else
				matrix[i][j] = INF;
		}
	}	
}



void input(std::istream& pin) {
	
	pin >> N >> M;
	
	init_mat(adj_mat, N, N);
	init_mat(via, N, N);	

	int source, dest;
	
	for(int i=0; i<M; i++) {
		pin >> source >> dest;
	
		adj_mat[source-1][dest-1] = 1;
		adj_mat[dest-1][source-1] = 1;
	}
}

int floyd_warshall() {
	int cnt = 0;
	for(int k=0; k<N; k++) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j]) {
					adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
					via[i][j] = k;
				}
			}
		}
	}
		for(int i=1; i<N; i++) {
			if(adj_mat[0][i] >= INF) cnt++;
		}
	return N-cnt-1;
}

int main() {
	
	input(cin);

	
	cout << 	floyd_warshall();
	
		

	return 0;
}
