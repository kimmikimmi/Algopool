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

string N;
int M;

void input(std::istream& pin) {
	pin >> N >> M;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	int len = N.size();
	string ans = "";
	int int_N = stoi(N);
	if(int_N*len > M) { 
		int numOfLoop = M/len + 1;

		for(int i=0; i<numOfLoop; i++) 
			ans += N;
		for(int i=0; i<M; i++) 
			printf("%c", ans[i]);
	} else {
		for(int i=0; i<int_N; i++) {
			printf("%d", int_N);
		}	
	}
	return 0;
}
