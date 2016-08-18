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
#define mat_t vector<vector<bool>>

int N,M;
mat_t adj_mat;

void input(std::istream& pin) {
	pin >> N >> M;
	adj_mat.assign(N+M+2, vector<bool>(N+M+2));
	
	int num_hut, id_hut;
	for(int i=1; i<=N; i++) {
		pin >> num_hut;
		adj_mat[0][i] = true; // s -> cows
		for(int j=0; j<num_hut; j++) {
			pin >> id_hut;
			adj_mat[i][N+id_hut] = true; // cows -> huts
			adj_mat[N+id_hut][N+M+1] = true; // huts -> t
		}
	}
}

bool find_path(int s) {
	vector<bool> bit_map(N+M+2, false);	
	vector<int> parents(N+M+2, -1);
	// 1. BFS를 이용한 경로 탐색
	// 2. 경로 발견 후 BFS에 사용중인 큐 비우고, 경로 업데이트, 카운트 1 증가
	queue<int> q;
	int q_front;

	q.push(s);
	parents[s] = s;
	bit_map[s] = true;

	while(!q.empty()) {
		q_front = q.front();
		q.pop();
		for(int i=1; i<N+M+2; i++) {
		
			if(adj_mat[q_front][i]) {
				if(!bit_map[i]){
				   	q.push(i);
					parents[i] = q_front;
					bit_map[i] = true;
				}
		//		cout << q_front << "-> " << i <<  endl;
				if(i == N+M+1) { // arrived at t
					// 경로 업데이트 
					int iter = i;		
					while(iter != 0) {
						adj_mat[parents[iter]][iter] = false;
						adj_mat[iter][parents[iter]] = true;	
						iter = parents[iter];
					}
		//			cout << "true "<< endl;
					return true;
				}
	
			}
		}			
	}
	return false;
}

int method_max_flow() {
	int cnt = 0;
	// 1. BFS를 이용한 경로 탐색
	// 2. 경로 발견 후 BFS에 사용중인 큐 비우고, 경로 업데이트, 카운트 1 증가
	while(find_path(0)) cnt++;
	return cnt;
}
void displayMat() {

	for(int i=0; i<N+M+2; i++) {
		for(int j=0; j<N+M+2; j++) {
			cout << adj_mat[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	input(cin);
//	displayMat();
//	cout << "---------------------" << endl;
	cout << method_max_flow() << endl;

//	cout << "---------------------" << endl;
//	displayMat();
	return 0;
}
