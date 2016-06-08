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
vector<vector<char>> mirror;
int K;

void input(std::istream& pin) {
	pin >> N;
	mirror.assign(N, vector<char>(N));
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			pin >> mirror[i][j];
		}
	}
	pin >> K;	
}
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void transform_lr() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N/2; j++) {
			swap(mirror[i][j], mirror[i][N-1-j]);
		}
	}
}

void transform_ud() {

	for(int i=0; i<N/2; i++) {
		for(int j=0; j<N; j++) {
			swap(mirror[i][j], mirror[N-1-i][j]);
		}
	}
}

void transform(int i) {
	switch(i) {
		case 1:
			break;
		case 2:
			transform_lr();
			break;
		case 3:
			transform_ud();
	}
}

void print() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << mirror[i][j];
		}
		cout << endl;
	}
}

int main() {
	input(cin);
	transform(K);
	print();
	return 0;
}
