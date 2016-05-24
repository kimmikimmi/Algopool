#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

#define MAX_SIZE 3000
/*

	a(i,j) = (1,1) ~ (i,j) 로 이루어진 정사각형 에 포함된 모든 숫자의 합.
	------------------------------
	|     1      |	2            |
	| -----------|---------------|
	|            |               |
	|     3      |      4        |
	------------------------------(i,j)
                1,2,3,4 사이의 좌표 : (a,b)
	
	4를 구하기 위해  a(i,j) - a(a,j) -a(i,b) + (a,b)을 한다.

	Time complexity O(n^2)
*/

/*
input format : 
2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3
*/	

int r,c;
int input_mat[MAX_SIZE+1][MAX_SIZE+1];
int rect_mat[MAX_SIZE+1][MAX_SIZE+1];
int num_points;

struct point {
	int x;
	int y;
};

std::vector<point> start_vec;
std::vector<point> end_vec;

void input(istream& in) {
	int temp;
	point p1,p2;
	in >> r >> c;
	for(int i=1 ; i<r+1; i++) {
		for(int j=1; j<c+1; j++) {
			in >> temp;
			input_mat[i][j] = temp;
		}
	}

	in >> num_points;
	p1.x = 0; p1.y = 0;
	start_vec.push_back(p1);
	end_vec.push_back(p1);
	for(int i=0; i<num_points; i++) {
		in >> p1.x >> p1.y >> p2.x >> p2.y;
		start_vec.push_back(p1);
		end_vec.push_back(p2);
	}


}

void set_rect_mat() {
	for(int i=1; i<r+1; i++) {
		for(int j=1; j<c+1; j++) {
			if(i==1 && j==1) {
				rect_mat[i][j] = input_mat[i][j];
			} else if (i == 1) {
				 rect_mat[i][j] = rect_mat[i][j-1] + input_mat[i][j];
			} else if(j==1) {
				rect_mat[i][j] = rect_mat[i-1][j] + input_mat[i][j];
			} else { 
				rect_mat[i][j] = rect_mat[i][j-1] + rect_mat[i-1][j] 
			          - rect_mat[i-1][j-1] + input_mat[i][j];
			}
		}
	}
}

int display_mat() {
	for(int i=0; i<r+1; i++) {
		for(int j=0; j<c+1; j++) {
			cout << rect_mat[i][j] << "  " ;
		}
		cout << endl;
	}
	return 0;
}

int method(int i) {
	return rect_mat[end_vec[i].x][end_vec[i].y] - rect_mat[end_vec[i].x][start_vec[i].y-1]
			-rect_mat[start_vec[i].x-1][end_vec[i].y] + rect_mat[start_vec[i].x-1][start_vec[i].y-1];
	
}

int main() {
	input(cin);
	set_rect_mat();
	// display_mat();
	for (int i = 1; i < num_points; ++i) 
	{
		cout << method(i) << endl;
	}
	cout << method(3);
	return 0;
}
