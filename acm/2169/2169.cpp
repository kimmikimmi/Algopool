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
/*
 *
 *
 * 양방향에서 오는 다이나믹 !!
 * Mat size N by M.
 *
 * O(NM)
 *
 */
using namespace std;

int N, M;

vector<vector<int>> mars;
vector<vector<int>> cache;

void input(std::istream& pin) {
	pin >> N >> M;

	mars.assign(N, vector<int>(M));
	cache.assign(N, vector<int>(M));
	for(int i=0; i<N; i++) 
		for(int j=0; j<M; j++) 
			pin >> mars[i][j];
}

int getSumBetween(vector<vector<int>>& vec, int r, int f, int t) {
	int start = f;
	int end = t;
	int sum = 0;

	if(start > end) 
		swap(start, end);
	
	for(int i=start; i<=end; i++) 
		sum += vec[r][i];

	return sum;
}

int loop_sol() {
	// init 1st line..

	vector<int> left_vec(M, -1);
	vector<int> right_vec(M, -1);

	for(int i=0; i<M; i++) {
		cache[0][i] = getSumBetween(mars, 0, 0, i);
	}

	for(int i=1; i<N; i++) {
		left_vec[0] = cache[i-1][0] + mars[i][0];
		right_vec[M-1] = cache[i-1][M-1] + mars[i][M-1];  
		for(int j=1; j<M; j++) 
			left_vec[j] = max(cache[i-1][j] + mars[i][j],
								left_vec[j-1] + mars[i][j]);
		for(int j=M-2; j>=0; j--) 		
			right_vec[j] = max(cache[i-1][j] + mars[i][j],
								right_vec[j+1] + mars[i][j]);
		for(int j=0; j<M; j++) 
			cache[i][j] = max(left_vec[j], right_vec[j]);
	}

	return cache[N-1][M-1];
}


int main() {

	input(cin);
	cout << loop_sol() << endl;

	return 0;
}
