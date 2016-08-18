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
queue<int> q;
void input(std::istream& pin) {
	pin >> N;
}

int method() {
	for(int i=1; i<=N; i++)
		q.push(i);

	while(q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front() << " ";
	return 0;
}

int main() {
	input(cin);
	method();
	 
	return 0;
}
