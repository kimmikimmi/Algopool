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

int R,C,ZR,ZC;
typedef vector<vector<char>> mat_t;
mat_t mat;

void input(std::istream& pin) {
	pin >> R >> C >> ZR >> ZC;
	char tmp;
	mat.assign(R, vector<char>(C));
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			pin >> tmp;
			mat[i][j] = tmp;
		}
	}
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}
}

int method() {
	//mat_t bigger_mat(R*ZR, vector<char>(C*ZC));
	for(int i=0; i<R; i++) {
		for(int a=0; a<ZR; a++) {
			for(int j=0; j<C; j++) {
				for(int k=0; k<ZC; k++) {
					cout << mat[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
