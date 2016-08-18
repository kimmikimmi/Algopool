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



mat_t in_degree;
mat_t out_degree;
vector<int> cache_in;
vector<int> cache_out;


void input(std::istream& pin) {
	
	pin >> N >> M;

	in_degree.assign(N, vector<int>(N));
	out_degree.assign(N, vector<int>(N));

	cache_in.assign(N, -1);
	cache_out.assign(N, -1);

	int source, dest;	

	for(int i=0; i<M; i++) {
		pin >> source >> dest;
	
		in_degree[dest-1][source-1] = 1;
		out_degree[source-1][dest-1] = 1;
	}
}
int cnt_in_degree(int n, int& cnt);
int cnt_out_degree(int n, int& cnt);

int out_degree_wrapper(int n) {
	int cnt = 0;
	cnt_out_degree(n, cnt);
	return cnt;
}


int cnt_out_degree(int n, int& cnt) {
	if(cache_out[n] != -1) {
		cnt += cache_out[n];
		return 0;
	}
	int tmp_cnt = 0;
	for(int i=0; i<N; i++) {
		if(in_degree[i][n] == 1) {
			//cnt++;
			tmp_cnt++;
			cnt_out_degree(i, tmp_cnt);
		}
	}
	cache_out[n] = tmp_cnt;
	cnt += cache_out[n];
	return 0;
}


int in_degree_wrpper(int n) {
	int cnt = 0;
	cnt_in_degree(n, cnt);
	return cnt;
}

int cnt_in_degree(int n, int& cnt) {
	if(cache_in[n] != -1) {
		cnt+= cache_in[n];
		return 0;
	}
	int tmp_cnt = 0;	
	for(int i=0; i<N; i++) {
		if(in_degree[n][i] == 1) {
			tmp_cnt++;
			cnt_in_degree(i, tmp_cnt);
		}
	}
	cache_in[n] = tmp_cnt;
	cnt += cache_in[n];
	return 0;
}


int main() {
	
	input(cin);
	// 1.indegree 처리 
	for(int i=0; i<N; i++) 
			cout <<  N - 1 - in_degree_wrpper(i) -  out_degree_wrapper(i)<< endl;
	return 0;
}
