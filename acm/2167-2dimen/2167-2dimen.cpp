#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;


/*
문제
2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 배열의 (i, j) 위치는 i행 j열을 나타낸다.

입력
첫째 줄에 배열의 크기 N, M(1≤N, M≤300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 배열이 주어진다. 그 다음 줄에는 합을 구할 부분의 개수 K(1≤K≤10,000)가 주어진다. 다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(i≤x, j≤y).

출력
K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 32bit-int 범위를 초과하지 않는다.
*/

#define MAX_SIZE 3000

int mat[MAX_SIZE+1][MAX_SIZE+1];
int sum_mat[MAX_SIZE+1][MAX_SIZE+1];
int r, c;
int num_points;

struct point
{
	int x;
	int y;
};

std::vector<point> start_vec;
std::vector<point> end_vec;

void input(istream& in) {
	
	int tmp;
	point p1, p2;
	in >> r >> c;

	for(int i=1; i<r+1; i++) {
		for(int j=1; j<c+1; j++) {
			in >> tmp;
			mat[i][j] = tmp;
		}
	}
	p1.x = 0; p1.y = 0;
	start_vec.push_back(p1);
	end_vec.push_back(p1);
	in >>  num_points;
	for(int i=0; i<num_points; i++) {
		in >> p1.x >> p1.y >> p2.x >> p2.y;
		start_vec.push_back(p1);
		end_vec.push_back(p2);
	}


}

void display_mat() {
	for(int i=0; i<r+1; i++) {
		for(int j=0; j<c+1; j++) {
			cout << sum_mat[i][j] << " ";
		}
		cout << endl;
	}
}

void set_sub_mat() {
	for(int i=1; i<r+1; i++ ) {
		for(int j=1; j<c+1; j++) {
			if(i==1 && j == 1) {
				sum_mat[i][j] = mat[i][j];
			} else if(j != 1) {
				sum_mat[i][j] = sum_mat[i][j-1] + mat[i][j];
			} else {
				sum_mat[i][j] = sum_mat[i-1][c] + mat[i][j];
			}
		}
	}
		
}
int method_sub(int i);
void method(int n) {
	for(int i=1; i<=n; i++) {
		// call method_sub();
		cout << method_sub(i) << endl;
	}
}

int method_sub(int i) {
	//if(start_vec[i].y == 1) return sum_mat[end_vec[i].x][1] - sum_mat[start_vec[i].x-1][c];

	return sum_mat[end_vec[i].x][end_vec[i].y] - sum_mat[start_vec[i].x][start_vec[i].y-1];
}


int main() {
	input(cin);

	set_sub_mat();

	display_mat();

	method(num_points);
	
	return 0;
}







