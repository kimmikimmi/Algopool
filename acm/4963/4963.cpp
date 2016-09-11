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
#include <queue>

using namespace std;

int w, h;
vector<vector<char>> board;

bool input(std::istream& pin) {
	pin >> w >> h;
	if(w == 0 && h == 0) return false;

	board.assign(h, vector<char>(w));
	
	for(int i=0; i<h; i++) 
		for(int j=0; j<w; j++) 
			pin >> board[i][j];

	return true;
}

int BFS(int x, int y) {
	
	pair<int, int> cell;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while(!q.empty()) {
		cell =q.front();
		q.pop();

		if(cell.first < 0 || cell.second < 0 || cell.first >= h || cell.second >= w) 
			continue;
		if(board[cell.first][cell.second] == '1') {
			board[cell.first][cell.second] = '0'; //island -> sea
			q.push(make_pair(cell.first-1, cell.second-1));
			q.push(make_pair(cell.first-1, cell.second));
			q.push(make_pair(cell.first-1, cell.second+1));

			q.push(make_pair(cell.first, cell.second-1));
			q.push(make_pair(cell.first, cell.second+1));

			q.push(make_pair(cell.first+1, cell.second-1));
			q.push(make_pair(cell.first+1, cell.second));
			q.push(make_pair(cell.first+1, cell.second+1));
		}
	}
	return 1;
}	

int cnt_island() {
	int cnt = 0;
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			if(board[i][j] == '1') {
				cnt += BFS(i, j);
				i = j = 0;
			}			
		}
	}
	return cnt;
}

int main() {
	while(input(cin)) 
		cout << cnt_island() << endl;
	
	return 0;
}
