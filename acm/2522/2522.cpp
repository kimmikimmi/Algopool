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

void input(std::istream& pin) {
	pin >> N;
}

int method() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i+j <N-1) cout << " ";
			else
				cout << "*";
		}	
		cout << endl;
	}
	for(int i=1; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i > j) cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}	
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
