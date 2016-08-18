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
vector<int> q; 

void input(std::istream& pin) {
	pin >> N;
	q.assign(N, 0);
	for(int i=0; i<N; i++) 
		q[i] = i+1;
}

int method() {
	while(!q.empty()) {
		q.erase(q.begin());
		q.push_back(q[0]);
		q.erase(q.begin());
	}
	
	return q[0];
}

int main() {
	input(cin);
	cout << method() << endl;
	return 0;
}
