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

using namespace std;

/*
 * Topological Sort Algorithm
 *
 * G=(V,E) // put information for directed graph
 *
 * 모든 정점의 진입 차수를 개산한다.
 * if(진입 차수가 0인 정점이 하나도 없다면)
 * -> Then 위상정렬 불가능
 *
 *  else {
 *		V(진입차수 == 0) 출력
 *		V(진입차수 == 0) 과 연결된 E 모두 삭제 
 *		각 정점의 차수 진입차수 수정
 *	}
 */

typedef vector<list<int>> adjlist_t;

adjlist_t adj_list;
vector<int> in_degree;

int N,M;

void input(std::istream& pin) {
	scanf("%d %d", &N, &M);
	int v1, v2;

	adj_list.assign(N, list<int>());
	in_degree.assign(N, 0);

	for(int i=0; i<M; i++) {	
		scanf("%d %d", &v1, &v2);
		adj_list[v1-1].push_back(v2-1);
		in_degree[v2-1]++;
	}

}

void topological_sort() {
	for(int i=0; i<N; i++) {

		if(in_degree[i] == 0) {
			printf("%d ", i+1);
			in_degree[i] = -1;
			if(!adj_list[i].empty()) {
				for(auto& it : adj_list[i])
					in_degree[it]--;
			}
			i = -1;
		}

	}
}

int main() {
	
	input(cin);
/*
	for(int i=0; i<adj_list.size(); i++) {
		cout << i << " : " ;
		for(auto& it : adj_list[i] ) {
			cout << it << " ";
		}
		cout << endl;
	}
	cout << "-------------" << endl;
	
	for(auto& it : in_degree) cout << it << endl;
*/
	topological_sort();
	return 0;
}
