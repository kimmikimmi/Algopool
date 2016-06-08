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

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int T;
	int N,M;
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> N >> M;
		int a,b;
		int mat[N][N];
		bool bitmap[N];
		for(int i=0; i<N; i++) bitmap[i] = false;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				mat[i][j] = 0;
			}
		}

		for(int i=0; i<M; i++) {
			cin >> a >> b;
			mat[a-1][b-1] = 1;
			mat[b-1][a-1] = 1;
		}
		int cnt = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(mat[i][j] == 1) {
					if(bitmap[i] == false) {
						bitmap[i] = true;
						cnt++;
					}
					if(bitmap[j] == false) {
						bitmap[j] = true;
						cnt++;
					}
					if(cnt == N) {
						cout << i+1 << endl;
						j=N;i=N;
					}
				}
				
			}
		}

	}
	return 0;
}
