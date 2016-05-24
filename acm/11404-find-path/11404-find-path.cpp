#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

#define MAX_SIZE 100

/*
문제
가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다. i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. i번째 줄의 i번째 숫자는 항상 0이다.

출력
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다. 정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
*/

/* 예제 입력


3
0 1 0
0 0 1
1 0 0


*/


int n; // 1 <= n <= 100
int adj_mat[MAX_SIZE][MAX_SIZE];
int sol_mat[MAX_SIZE][MAX_SIZE];
int visited[100];

void input(istream& in) {
	int tmp;
	in >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			in >> tmp;
			adj_mat[i][j] = tmp;
		}
	}
}

//
void DFS(int v) {
	int i;

	visited[v] = 1; // 정점 v를 방문했다고 표시
	for(i=0; i<=n; i++) {
		if(i==v) sol_mat[v][i] = 1;
		//정점 v와 i가 연결되었고, 정점 i를 방문하지 않았다면
		if(adj_mat[v][i] == 1 && !visited[i]) {
			sol_mat[i][v] = sol_mat[v][i] = 1;
			cout << v << "->" << i << endl; 
			DFS(i);
		}
	}

} 

void method() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << sol_mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	input(cin);
	DFS(0);
	method();
	return 0;
}
