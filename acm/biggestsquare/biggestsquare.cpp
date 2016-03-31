#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_ROW 1001
#define MAX_COL 1001
/*
n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.

0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다. 

입력
첫째 줄에 n, m(1 ≤ n, m ≤ 1,000)이 주어진다. 다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.

출력
첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.
*/

int mat[MAX_ROW][MAX_COL]; // a matrix for saving the main matrix to solve.

int  cache[MAX_ROW][MAX_COL]; // 2 dimentional array for DP

int m;	// row of input matrix
int n;  // col of input matrix

/*
@param: null
@return : null
@Description :
	initialising two 2 dimensional array to -1
*/
void initMat() {

	for(int i=0; i<MAX_ROW; i++)
		for(int j=0; j<MAX_COL; j++) {
			mat[i][j] = -1;
			cache[i][j] = -1;
		}

}


/*
	Trial 1.
	-Brute force.
	@param : null
	@return : the length of a line of square.
	@description :
		Using a vector which has the number of maximum square as cell(i,j) is the top left cell of the sqaure,
			 line increases in every single loop.. and erase an element in case when it is impossible to make the square 
			 	of which size is line by line.
*/
int method() {
	if(squares.empty()) return 0;
	
	int line = 2;
	int index = 0;
	bool isSquare = true;

	while(!squares.empty()) {
		int r = squares[index].x;
		int c = squares[index].y;

		if( (r + line-1 != -1) && (c + line-1 != -1) ) {
			
			for(int i=0; i<line; i++) {
				if((mat[r + line-1][c + i] != 1) || (mat[r + i][c + line-1] != 1)) {
						squares.erase(squares.begin() + index);
						isSquare = false;
						break;
				}				
			}

			if(isSquare) {
				index++;
			} else {
				isSquare = true;
			} 	
			
		} else {
			squares.erase(squares.begin() + index);
		}

		if(!squares.empty() && index == squares.size()) {
			index = 0;
			line++;
		}
	}

	return line-1;
}

/*
	trial 2 Recursion.
	cache[i][j] : in case that cell[i][j] is the bottom right side, the maximum side able to make.
					with Dynamic programming.
	@param : int int
	@return int

*/
int recursive_sol(int i, int j) {
	
	if(cache[i][j] != -1) {
		
		return cache[i][j];
	}
	if(mat[i][j] == 0) {
		
		cache[i][j] = 0;
		
		return cache[i][j];
	}
	if(i == 0 || j == 0) {
		
		  cache[i][j] = 1;
		
		  return cache[i][j];
	}
	
	
	cache[i][j] = min( min(recursive_sol(i-1, j-1), recursive_sol(i, j-1) ), 
						min(recursive_sol(i-1, j-1), recursive_sol(i-1, j) )
						) + 1;

	return cache[i][j];

}
/*
	@param : null
	@return : int (square root of the final answer)
	@description : find the max side of the square using secursive_sol(int int)

*/
int get_solution() {
	int max = 0;
	int tmp;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			tmp = recursive_sol(i,j);
			if(max < tmp) max = tmp;
		}
	}
	return max;
}
/*
	@param : istream
	@return : void

	@description :
			using istream object, read n, m, and insert to mat as integer.
*/
void input(istream& in) {
	in >> n >> m;
	char temp;

	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) {
			in >> temp;
			mat[i][j] = temp - '0';
		
		}
	

}

int main() {
	initMat();

	input(cin);

	// int ans = pow(method(), 2) ;
	// cout << ans << endl;

	cout << pow(get_solution(),2);
	return 0;
}
