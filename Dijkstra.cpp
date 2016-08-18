#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>


using namespace std;

#define INF   INT_MAX - 100000;
// const int INFINITE = 1000;

//The shortest path algorithm in case weights of all edges is more than 0, invented by Dijkstra.

int ** adjMat;
int numOfVertices;
int * dist;


void input() {
	// get graph info from the file, and store to adjMat.
	int num, size;
	cin >> numOfVertices >> num;


	// initializing an adjacent matrix.
	adjMat = new int*[numOfVertices];
	for(int i=0; i<numOfVertices; i++) {
		adjMat[i] = new int[numOfVertices];
	}

	for(int i=0; i<numOfVertices; i++) {
		for(int j=0; j<numOfVertices; j++) {
			adjMat[i][j] = INF;
		}
	}

	int i, j;

	for(int k=0; k<num; k++) {

		cin >> i >> j >> size;		
		adjMat[i][j] = size;
		
	}

}

void displayMat() {
	cout << "display here" << endl;
	for(int i=0; i<numOfVertices; i++) {
		for(int j=0; j<numOfVertices; j++) {
			cout << adjMat[i][j] << "\t";
		}
		cout << endl;
	}
}



void Dijkstra(int v) {
	   
        int min;
        cout << "asdsadsa" << endl;
 		int visited[numOfVertices];
 		int dist[numOfVertices];
 		int currentVertex;
 		for(int i=0; i<numOfVertices; i++) {
 			visited[i] = 0;
 			dist[i] = INF;
 		}

        dist[v] = 0;        // 시작점의 거리 0
 
        for (int i =0; i<numOfVertices; i++) {
                min = INF;
               
                for (int j =0; j<numOfVertices; j++) {
                        if (visited[j] == 0 && min > dist[j])    // 갈수 있는 정점중에 가장 가까운 정점 선택
                        {
                                min = dist[j];
                                currentVertex = j;
                        }
                }
 
                visited[currentVertex] = 1;   // 가장 가까운 정점으로 방문, i정점에서 가장 가까운 최단경로 v
       
                for (int j=0;j<numOfVertices; j++) {
                        if ( dist[j] > dist[currentVertex] + adjMat[currentVertex][j])       // 방문한 정점을 통해 다른 정점까지의 거리가 짧아지는지 계산하여 누적된값 저장
                                dist[j] = dist[currentVertex] + adjMat[currentVertex][j];
                }
        }
        
      for(int i=0; i<numOfVertices; i++) {
      	cout << dist[i] << endl;
      }
}



int main(void)
{
	/* code */
	cout << "it goes" << endl;
	input();
	displayMat();
	 Dijkstra(0);
	for(int i=0; i<numOfVertices; i++) {
		cout << "최단거리 " << dist[2]<< endl;
	}
	return 0;
}
