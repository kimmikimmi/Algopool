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
typedef vector<int> row_t;

int T;
int n;

int method(int n, mat_t& source, mat_t& dest) {

	if(n == 0) {
		dest[0][n] = source[0][n];
		dest[1][n] = source[1][n];	
	} else if( n == 1) {
		dest[0][n] = source[0][n] + dest[1][n-1];
		dest[1][n] = source[1][n] + dest[0][n-1];
	} else {
		dest[0][n] = source[0][n] + max({dest[1][n-1], dest[1][n-2]});
		dest[1][n] = source[1][n] + max({dest[0][n-1], dest[0][n-2]});
	}
	return dest[0][n] > dest[1][n] ? dest[0][n] : dest[1][n];

}

int main() {
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> n;
		
		mat_t input_mat(2, row_t(n));
		mat_t res_mat(2, row_t(n));
		
		for(int j=0; j<2; j++) 
			for(int k=0; k<n; k++) 
				cin >> input_mat[j][k];

		for(int j=0; j<n-1; j++) 
			method(j, input_mat, res_mat);
		cout << method(n-1, input_mat, res_mat) << endl;
		
	}

	return 0;
}
