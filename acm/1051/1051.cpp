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

int N,M;
vector<vector<char>> input_vec;
vector<vector<int>> sol_vec;


void init_sol_vec() {
	for(int i=0; i<N; i++) 
		sol_vec[i][0] = 1;
	for(int i=0; i<M; i++)
		sol_vec[0][i] = 1;
}
void input(std::istream& pin) {
	pin >> N >> M;

	input_vec.assign(N, vector<char>(M));
	sol_vec.assign(N, vector<int>(M));
	char ch_buf;
	for(int i=0; i<N; i++) 
		for(int j=0; j<M; j++) { 
			pin >> ch_buf;
			input_vec[i][j] = ch_buf;
		}

}

int method() {
	for(int i=1; i<N; i++) {
		for(int j=1; j<M; j++) {
			int edge = i<j ? i : j;

//			cout << "i = " << i << " j = " << j << " edge = " << edge << endl;
			while(edge != 0) {
				// 다른 두 점 체크
				if( (input_vec[i-edge][j-edge] == input_vec[i][j]) &&
					   (input_vec[i][j-edge] == input_vec[i][j]) &&
					   (input_vec[i-edge][j] == input_vec[i][j]) ) {
					sol_vec[i][j] = edge + 1;
					
//					cout <<"Inner! " << "i = " << i << " j = " << j << " edge = " << edge << endl;
//					cout << input_vec[i-edge][j-edge] << " " << input_vec[i][j-edge] << " " << 
//						input_vec[i-edge][j] << " " << input_vec[i][j] << endl;
					break;	
				}
				edge --;
				if(edge == 0 ) sol_vec[i][j] = 1;
			}
			
		}
	}
	
	return 0;
}

int main() {
	
	input(cin);
	init_sol_vec();

//	for(int i=0; i<N; i++) {
//		for(int j=0; j<M; j++) {
//			cout << input_vec[i][j] << " ";
//		}
//		cout << endl;
//	}
	method();
	int max_val = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(sol_vec[i][j] > max_val) max_val = sol_vec[i][j]; 
		}
	}
	cout << max_val*max_val;
//	for(int i=0; i<N; i++) {
//		for(int j=0; j<M; j++) {
//			cout << sol_vec[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	return 0;
}
