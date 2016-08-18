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
queue<int> my_q;

int method() {
	return 0;
}

int main() {
	cin >> N;
	string op;
	int int_elem;
	for(int i=0; i<15; i++) {
		cin >> op;
		if(op == "push") {
			cin >> int_elem;
			my_q.push(int_elem);
		} else if(op == "pop") {
			if(my_q.empty()) cout << -1 << endl;
			else {
				cout << my_q.front() << endl;
				my_q.pop();
			}
		} else if(op == "size") cout << my_q.size() << endl;
		else if(op == "empty") {
			if(my_q.empty()) cout << 1 << endl;
			else 
				cout << 0 << endl;
		}else if(op == "front") {
			if(my_q.empty()) cout << -1 << endl;
			else
				cout << my_q.front() << endl;
		} else if(op == "back") {
			if(my_q.empty()) cout << -1 << endl;
			else
				cout << my_q.back() << endl;
	}

	}
	return 0;
}
