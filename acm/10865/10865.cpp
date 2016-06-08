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
int N;
int M;

void input(std::istream& pin) {
	pin >> N >> M;
}

int method() {
	vector<int> relation(N+1,0);
	int a,b;
	for(int i=1; i<=M; i++) { 
		scanf("%d %d", &a, &b);
		relation[a] ++;
		relation[b] ++;
	}
	for(int i=0; i<N; i++) {
		printf("%d\n", relation[i+1]);
	}	
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
