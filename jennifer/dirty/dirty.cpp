#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 다익스트라 알고리즘을 적용하여 해를 찾았습니다.
// 주어진 입력에 대해 인접행렬을 구현하여 생성한 인접행렬에 대하여 다익스트라 그래프 최단거리 알고리즘을 통하여 해를 구하였습니다.
#define INF 10000


int ** board;
int N;
int ** adj_mat;
std::vector<int> visit;
std::vector<int> dist;

// 행열의 mat[i][j] -> mat[size - i][j] 로 스왑할 떄 사용
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// 입력받고, 사용할 변수들을 초기화 합니다.
void input(istream& in) {
	in >> N;
	char temp;
	board = new int*[N];
	adj_mat = new int*[N*N];
	
	for(int i=0; i<N; i++) {
		board[i] = new int[N];
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			in >> temp;
			board[i][j] = temp - '0';
		}
	}
	for(int i=0; i<N*N; i++) {
		adj_mat[i] = new int[N*N];
	}

	for(int k=0; k<N*N; k++) {
 		dist.push_back(INF);
 		visit.push_back(0);
 	}

}

// 다익스트라 알고리즘을 구하기 위한 인접행렬을 미리 INF로 초기화 합니다.
void init_adj_mat() {
	for(int i=0; i<N*N; i++) {
		for(int j=0; j<N*N; j++) {
			adj_mat[i][j] = INF;
		}
	}
}

// 입력을 읽기 쉬운 모양으로 뒤집었습니다.
void reverse_mat() {
	for(int i=0; i<N/2; i++) 
		for(int j=0; j<N; j++) 
			swap(board[i][j], board[N-i-1][j]);
	
}

// 인접행렬의 값을 채웁니다.
void fill_adj_mat() {

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i != 0) {
				adj_mat[(i-1)*5 + j][i*5 + j] = board[i][j];
			}
			if(i != N-1) {
				adj_mat[(i+1)*5 + j][i*5 + j] = board[i][j];
			}
			if(j != 0) {
				adj_mat[(i)*5 + j-1][i*5 + j] = board[i][j];
			}
			if(j != N-1) {
				adj_mat[(i)*5 + j+1][i*5 + j] = board[i][j];
			}

			
		}
	}
	for(int i=0; i<N*N; i++) {
		adj_mat[N*N-1][i] = INF;
	}
}

// 다익스트라 알고리즘입니다. dist[]의 경우 dist[i]는 0노드에서 [i]노드까지의 최단경로를 찾습니다.
int dijkstra() {		
		
        int i,j;
        int min;
        int v;
 		
        dist[0] = 0;// 시작점의 거리는 0으로 초기화 합니다.
 
        for(i =0; i<N*N; i++) {
                min = INF;
               
                for (j=0; j<N*N; j++) {
                    if ( visit[j] == 0 && min > dist[j]) { // 아직 방문하지 않은 정점들 중에 가장 가까운 정점 선택합니다.
                            min = dist[j];
                            v = j;
                    }
                }
                visit[v] = 1;   
                for (j=0; j< N*N; j++) {
                        if (dist[j] > dist[v] + adj_mat[v][j])       // 방문한 정점을 통해 다른 정점까지의 거리가 짧아지는지 계산하여 누적된값 저장
                                dist[j] = dist[v] + adj_mat[v][j];
                }
        }
        // for(int i=0; i<N*N; i++) cout << dist[i] << endl;
        return dist[N*N-1] > 100 ? 100 : dist[N*N-1];
}

int main() {
	input(cin);
	reverse_mat();
	init_adj_mat();
	fill_adj_mat();

	cout << dijkstra();
	
	return 0;
}
