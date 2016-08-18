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
vector<int> board;
int N, M;
void input(std::istream& pin) {
	pin >> N >> M;
	board.assign(N,0);
	int a,b;
	for(int i=0; i<M; i++) {
		pin >> a >> b;
		board[a-1]++;
		board[b-1]++;
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	for(auto&it : board) cout << it << endl;
	return 0;
}
