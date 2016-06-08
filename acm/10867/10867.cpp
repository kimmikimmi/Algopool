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

int N;


void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	scanf("%d", &N);
	int tmp;
	vector<bool> chk_board(2001,false);
	
	vector<int> int_bag(N);
	for(int i=0; i<N; i++) {
		scanf("%d", &tmp);
		chk_board[tmp + 1000] = true;
	}

	for(int i=0; i<2001; i++) 
	   if(chk_board[i]) cout << i-1000 << " ";	
	return 0;
}
