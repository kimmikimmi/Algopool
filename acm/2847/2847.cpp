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
vector<int> levels;
void input(std::istream& pin) {
	pin >> N;
	levels.assign(N, 0);
	for(int i=0; i<N; i++) {
		int tmp;
		pin >> tmp;
		levels[i] = tmp;
	}	
}

int method() {
	int cnt = 0;
	for(int i=N-2; i>=0; i--) {
		if(levels[i+1] <= levels[i]) {
			
			cnt += levels[i] - levels[i+1] + 1;
			levels[i] -= levels[i] - levels[i+1] + 1;
		}
	}
	return cnt;
}

int main() {
	input(cin);
	cout << method() << endl;



	return 0;
}
