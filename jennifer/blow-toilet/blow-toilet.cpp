#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

/*
	시간이 없어서 한번에 연속된 하나의 라인만 제거하는 경우에 대해서 해답을 구해보았습니다.

*/

#define MAX_SIZE 16

int N; // N*N matrix;
int M; // 연속한 M개를 한번에 날려버릴 수 있다.

char mat[MAX_SIZE][MAX_SIZE]; // 인풋으로 받은 행렬입니다.

int zero_row; //  행 들 중에서 0으로만 차있는 행의 수 
int zero_col; //  열 들 중에서 0으로만 차있는 열의 수

std::vector<int> row_vec; // 각 행에 1이 몇개있지 저장합니다
std::vector<int> col_vec; // 각 열에 1이 몇개인지 저장합니다.

void input(istream& in) {
	char temp;
	in >> N >> M;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			in >> temp;
			mat[i][j] = temp;
		}
	}
}


// i 번째 row의 1의 개수를 샙니다.
int count_row(int i) {
	int cnt = 0;
	for(int j=0; j<N; j++) {
		if(mat[i][j] == '1') {
			cnt++;
		} 
	}
	return cnt;
}


//i 번쨰 col의 1의 개수를 샙니다.
int count_col(int i) {
	int cnt = 0;
	for(int j=0; j<N; j++) {
		if(mat[j][i] == '1') {
			cnt++;
		} 

	}
	return cnt;
}

void update_vectors() {
	int row, col;

	row_vec.clear();
	col_vec.clear();
	zero_row = 0;
	zero_col = 0;

	for(int i=0; i<N; i++) {
		row = count_row(i);
		col = count_col(i);

		if(row == 0) zero_row++;
		if(col == 0) zero_col++;

		row_vec.push_back(row);
		col_vec.push_back(col);
	}
}

bool isDone() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(mat[i][j] == '1') return false;
		}
	}
	return true;
}

int method() {
	int sol = 0;
	while(!isDone()) {
		update_vectors();
		int max_index = 0;
		int max_value = 0; 
		if(zero_row > zero_col) { // 모든 원소가 0인 행이 열보다 많은 경우
		// row_vec에서 값이 가장 큰 놈의 값을 0으로 변한다.
		// 그 후 메트릭스에 그 행 모두 0으로 초기화 한다.
		
			for(int i=0; i<row_vec.size(); i++) {
				if(row_vec[i] > max_value) {
					max_value = row_vec[i];
					max_index = i;
				}
			}
			row_vec[max_index] = 0;
			
			for(int i=0; i<N; i++) 
				mat[max_index][i] = '0';
			
		} else {
			//col_vec에서 값이 가장 큰 놈을 제거한다.
			for(int i=0; i<col_vec.size(); i++) {
				if(col_vec[i] > max_value) {
					max_value = col_vec[i];
					max_index = i;
				}
			}
			col_vec[max_index] = 0;
			for(int i=0; i<N; i++) 
				mat[i][max_index] = '0';
		}
		sol++;
	}
	
	return sol;

}

int main() {
	input(cin);
	
	 cout << method() << endl;

	return 0;
}
