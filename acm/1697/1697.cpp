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

int N, K;
vector<bool> bit_map;

void input(std::istream& pin) {
	pin >> N >> K;
}


int primitive_BFS(int source, int dest) {
	int step = 0;
	queue<int> q;

	q.push(source);

	for(int i=1;;) {
		int current = q.front();
		//cout << current << endl;
		if(current == dest) break;
		q.pop();
		
			q.push(current-1);
			q.push(current+1);
			q.push(current*2);
		if(q.size() == pow(3,i)) {
			step ++;
			i++;
		}
	}
	return step;
}
struct node {
	int value;
	int depth;
};

int BFS(int source, int dest) {
	queue<node> q;
	node n;
	n.value = source;
	n.depth = 0;
	q.push(n);
	node current;
	int step = 0;
	bit_map[source] = true;
	while(1) {
	
		current = q.front();
		//cout << current.value  << ", " << current.depth << endl;	
		if(current.value == dest) break;	
		q.pop();
		step = current.depth;		
		if(current.value > 0 && !bit_map[current.value-1]) {
			n.value = current.value-1;
			n.depth = step+1;
			q.push(n);
			bit_map[current.value-1] = true;
		} if(current.value < dest && !bit_map[current.value+1] ) {
			n.value = current.value+1;
			n.depth = step+1;
			q.push(n);
			bit_map[current.value+1] = true;
		}if(current.value * 2 <= 100000 && !bit_map[2* current.value]) {
			n.value = current.value*2;
			n.depth = step+1;
			q.push(n);
			bit_map[current.value*2] = true;
		}


	}


	return current.depth;
}

int main() {
	input(cin);
	bit_map.assign(200001, false);
	cout << BFS(N, K);
	return 0;
}
