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
//vector<vector<char>> board;

void input(std::istream& pin) {
	char pos;
	int cnt = 0;
	//board.assign(8, vector<char>(8));
	for(int i=0; i<8; i++) 
		for(int j=0; j<8; j++) {
			pin >> pos;
			if(pos == 'F') {
				if(i%2 ==1 && j%2 == 1) 
				   cnt++;
				else if(i%2 == 0 && j%2 == 0)
					cnt++;	
			}
		}
	cout << cnt;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	return 0;
}
