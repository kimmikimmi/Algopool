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
int N;

void input(std::istream& pin) {
	pin >> N;
}

int main() {
	input(cin);
	int op;

	priority_queue<int, vector<int>, greater<int> > min_heap;

	for(int i=0; i<N; i++) {
		scanf("%d", &op);
			
		if(op == 0) {
			if(min_heap.empty()) {
				printf("0\n");
				continue;
			}
			// 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거.
			printf("%d\n", min_heap.top());
			min_heap.pop();
		}  else {
			// 자연수인 경우 그값을 최소 힙에 넣는다.
			min_heap.push(op);
		}	

	}

	return 0;
}
