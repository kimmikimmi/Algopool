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

typedef vector<vector<int>> mat_t;

int r; int c;
mat_t A;
mat_t B;


void assign_value(std::istream& pin, mat_t& matrix) {
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			int temp;
			pin >> temp;
			matrix[i][j] = temp;
		}
	}
}


void input(std::istream& pin) {
	pin >> r >> c;
	A.assign(r, vector<int>(c));
	B.assign(r, vector<int>(c));
	assign_value(pin, A);
	assign_value(pin, B);
}

void print_mat(mat_t x) {
	for(int i=0; i<r; i++) { 
		for(int j=0; j<c; j++) {
			cout << x[i][j] << "\t";	
		}
		cout << endl;
	}
}	
mat_t add(mat_t mat1, mat_t mat2) {
	mat_t sol_mat(r, vector<int>(c));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			sol_mat[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return sol_mat;
}

int main() {
	input(cin);
	print_mat(add(A,B));
	return 0;
}
