#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <tuple>
#include <set>

using namespace std;
typedef vector<vector<int>> box;
typedef pair<int,int> tomato_cell;

int r;
int c;
box mat;
int possible_toms;

void input(std::istream& pin) {
	pin >> c >> r;
	int tmp;
	possible_toms = r * c;
	mat.assign(r+2, vector<int>(c+2));
	for(int i=0; i<r+2; i++) {
		for(int j=0; j<c+2; j++) {
			if(i == 0 || i == r+1 || j ==0 || j == c+1) {
				mat[i][j] = -1;
				continue;
			}
			pin >> tmp;
			if(tmp == -1) possible_toms--;
			mat[i][j] = tmp;
		}
	}
}

void spread_and_push(queue<tomato_cell>& Q, box& tom_box) {
	tomato_cell cur_cell = Q.front();
	Q.pop();
	if(tom_box[cur_cell.first-1][cur_cell.second] == 0) {
		Q.push(make_pair(cur_cell.first-1, cur_cell.second));
		tom_box[cur_cell.first-1][cur_cell.second] = 1;
	}	
	if(tom_box[cur_cell.first][cur_cell.second-1] == 0) {
		Q.push(make_pair(cur_cell.first, cur_cell.second-1));
		tom_box[cur_cell.first][cur_cell.second-1] = 1;
	}
	if(tom_box[cur_cell.first+1][cur_cell.second] == 0) {
		Q.push(make_pair(cur_cell.first+1, cur_cell.second));
		tom_box[cur_cell.first+1][cur_cell.second] = 1;
	}
	if(tom_box[cur_cell.first][cur_cell.second+1] == 0) {
		Q.push(make_pair(cur_cell.first, cur_cell.second+1));
		tom_box[cur_cell.first][cur_cell.second+1] = 1;
	}
}

int get_time_tomato_mature(box& tom_box) {
	queue<tomato_cell> Q;
	int time_slice = 0;
	
	// loops initializing Q
	for(int i=1; i<r+2; i++) 
		for(int j=1; j<c+2; j++) 
			if(tom_box[i][j] == 1) Q.push(make_pair(i,j));
			
	//Spread out to adjacent slots;
	while(!Q.empty()) {
		spread_and_push(Q, tom_box);
		time_slice++;
	}		
	
	return time_slice;
}

int main() {
	input(cin);
	cout << get_time_tomato_mature(mat) << endl;
	for(int i=0; i<r+2; i++) {
		for(int j=0; j<c+2; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
