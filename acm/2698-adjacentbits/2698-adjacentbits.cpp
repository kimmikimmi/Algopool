#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;
/*
 *
 *
 * 문제
 * 0과 1로 이루어진 수열 S가 있다. S의 첫 수는 s1이고, 마지막 수는 sn이다. S의 인접한 비트의 개수는 다음과 같이 구할 수 있다.
 *
 * s1*s2 + s2*s3 + s3*s4 + ... + sn-1 * sn
 *
 * 위의 식을 이용하면 수열 S에서 인접한 1의 개수를 구할 수 있다. 예를들어, 011101101의 인접한 비트의 개수는 3이 되고, 111101101은 4, 010101010은 0이 된다.
 *
 * 수열 S의 크기 n과 k가 주어졌을 때, 인접한 비트의 개수가 k인 수열 S의 개수를 구하는 프로그램을 작성하시오.
 *
 * 예를 들어, n이 5이고, k가 2이면, 수열 S가 될 수 있는 수열은 다음과 같이 6가지가 있다.
 *
 * 11100, 01110, 00111, 10111, 11101, 11011
 *
 * 입력
 * 첫째 줄에 테스트 케이스의 수 T(1<=T<=1,000)가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 숫자 2개가 공백으로 구분되어 이루어져 있다. 첫 번째 숫자는 n이고, 두 번째 숫자는 k이다. n은 100을 넘지 않는다.
 *
 * 출력
 * 각 테스트 케이스에 대해 인접한 비트의 개수가 k인 수열 S의 개수를 한 줄에 하나씩 출력한다. 이 값은 2147483647보다 작거나 같다.
 * */


/*
 *	0	1	2	3	4	5
  0 1	0	0	0	0	0
  1 2	0	0	0	0	0		
  2 3	1	0	0	0	0
  3 5	2	1	0	0	0	
  4 8	5	2	1	0	0
  5 13	10	6	2	1	0
*/
int test_cases;
int adj_bits[101][100];
vector<int> rows;
vector<int> cols;

void input(istream& in) {
	int row,col;
	in >> test_cases;
	for(int i=0; i<test_cases; ++i) {
	    in >> row >> col;
		rows.push_back(row);
		cols.push_back(col);
	}
}

void set_adj_bits() {
    for(int i=0; i<101; i++) {
	    for(int j=0; j<100; j++) {
            if(i==0 && j == 0) adj_bits[0][0] = 1;
			else if(i==1 && j== 0) adj_bits[1][0] = 2;
			else if( i <= j) adj_bits[i][j] = 0;
			else if(j == 0) {
			    	adj_bits[i][j] = adj_bits[i-1][j] + adj_bits[i-2][j];
			} else {
				adj_bits[i][j] = adj_bits[i-1][j-1] + adj_bits[i-1][j] + adj_bits[i-2][j] - adj_bits[i-2][j-1];
			}
		}
	}	
}

void method() {	

}

int main() {
	input(cin);
	set_adj_bits();
	for(int i=0; i<test_cases; i++) 
	cout << adj_bits[rows[i]][cols[i]]  << endl;
	return 0;
}
