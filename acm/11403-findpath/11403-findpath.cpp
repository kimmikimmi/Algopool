#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <stack>
#include <stdio.h>

using namespace std;

int mtx[101][101];
int ans[101][101];
int visit[101];
int n;

//DFS 함수
void DFS(int v)
{
    visit[v] += 1;   //무조건 방문하면 안됨! 고쳐야 하는부분
    for (int i = 0; i < n; i++)
    {
        //가는 길이 있을때 & 방문하지 않았을 때
        if (mtx[v][i] == 1 && visit[i] < 2)
            DFS(i);
    }
}
 



// typedef std::vector< std::vector<int>> matrix;
// typedef std::vector< std::list<int>> adjacent_list;

// matrix adj_mat;
// int N;
// adjacent_list adj_list;
// matrix all_possible_paths;

// int input(istream& in) {
// 	int tmp;
// 	in >> N;
// 	adj_mat.assign(N, std::vector<int>(N));
// 	all_possible_paths.assign(N, std::vector<int>(N));
// 	for(int i=0; i<N; i++) 
// 		for(int j=0; j<N; j++) {
// 		   in >> tmp;
// 		   adj_mat[i][j] = tmp;
// 		}	   

// 	if(N >0 && N <100) return 1;
	
// 	return 0;
// }

// void DFSUtil(int v, bool visited[]) {
// 	visited[v] = true;
	
// 	cout << v << " ";
	
// 	// Recur for all the vertices adjacent to this vertex
// 	for(auto& iter : adj_mat[v]) {
// 		if(iter == 1 && !visited[v]) {
// 		//if(!visited[iter]) {
		
// 			DFSUtil(iter, visited);	
// 		}
// 	}
// }
// int DFS(int v) {
// 	bool* visited = new bool[N];
// 	for(int i=0; i<N; i++) visited[i] = false; // intializing visited array.

// 	// Call the recursive helper function to print DFS traversal
// 	stack<int> s;
// 	s.push(v);
// 	while(!s.empty()) {
// 		int u = s.top();
// 		s.pop();
// 		if(!visited[u]) {
// 			visited[u] = true;
			 
// 			for(int i=0; i<N; i++) {
				
// 				if(adj_mat[u][i] == 1) {
// 					s.push(i);
// 					all_possible_paths[i][u] = 1;
// 				}
// 			}
// 		}
// 	}
// 	return 0;


// }
// void make_all_possible() {
// 	for(int i=0; i<N; i++) {
// 		for(int j=0; j<N; j++) {
// 			all_possible_paths[i][j] = all_possible_paths[i][j] | adj_mat[i][j];
// 			if(i==j) all_possible_paths[i][j] = 1;
// 		}

// 	}
// }

int main() {
	// input(cin);
	// for(int i=0; i<N; i++) { 
	// 	for(int j=0; j<N; j++) {
	// 		cout << adj_mat[i][j] << "\t";
	// 	}cout << endl;
	// }
	// DFS(0);
	// make_all_possible();
	// for(int i=0; i<N; i++) { 
	// 	for(int j=0; j<N; j++) { 
	// 		cout << all_possible_paths[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }

	scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d ", &mtx[i][j]);
    }
 
  //메인문의 DFS 포문부분
    for (int i = 0; i < n; i++)
    {
        DFS(i);
 
        //방문한 점을 결과 행렬에 넣음 & 초기화
        for (int j = 0; j < n; j++)
        {
            //i==j면서 2가 안되었을때는 0으로
            if (i == j && visit[j] != 2)
            {
                ans[i][j] = 0;
                visit[j] = 0;
                continue;
            }
            ans[i][j] = visit[j];
            visit[j] = 0;
        }
    }
 
//출력부분
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //2인 경우 1로 고쳐줌
            if (ans[i][j] == 2)
                ans[i][j]--;
            printf("%d ", ans[i][j]);
        }           
        puts("");
    }
	return 0;
}
