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
typedef vector<int> col;

mat_t input_mat;
mat_t filtered_mat;
int R,C;
int T;

void input(std::istream& pin) {
	pin >> R >> C;
	input_mat.assign(R, col(C));
	for(int i=0; i<R; i++) 
		for(int j=0; j<C; j++) 
			pin >> input_mat[i][j];
	pin >> T;	
}

int find_mid_val(int r, int c, mat_t& target_mat) {
	vector<int> tmp_list;

	for(int i=r-1; i<=r+1; i++) 
		for(int j=c-1; j<=c+1; j++)
			tmp_list.push_back(target_mat[i][j]);

	sort(tmp_list.begin(), tmp_list.end());
	//for(auto& it : tmp_list) cout << it << " ";
	//cout << endl;
	
    return tmp_list[4];
}

void display_mat(mat_t& target_mat) {
	for(int i=0; i<R-2; i++) {
		for(int j=0; j<C-2; j++) {
			cout << filtered_mat[i][j] << " ";
		}
		cout << endl;
	}	
}

int method() {
	int noise = 0;
	filtered_mat.assign(R-2, col(C-2));
	
	for(int i=0; i<R-2; i++) {
		for(int j=0; j<C-2; j++) {
			filtered_mat[i][j] = find_mid_val(i+1, j+1, input_mat);
			if(filtered_mat[i][j] >= T) noise++;		
		}
	}
	//display_mat(filtered_mat);
	return noise;
}


int main() {
	input(cin);
	cout << method();
	return 0;
}
