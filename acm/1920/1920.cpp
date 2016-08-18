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

int N,M;
map<int, bool> my_map;

void input(std::istream& pin) {
	pin >> N;
	int tmp;

	for(int i=0; i<N; i++) {
		scanf("%d", &tmp);
		my_map[tmp] = true;	
	}

	pin >> M;
	for(int i=0; i<M; i++) {
		scanf("%d", &tmp);
		if(my_map[tmp]) printf( "1\n" );
		else
			printf("0\n");
	}
		
}

int method() {
	input(cin);
	return 0;
}

int main() {
	method();
	return 0;
}
