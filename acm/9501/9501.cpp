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
int T;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> T;
	for(int i=0; i<T; i++) {
		int N, D;
		int cnt = 0;
		cin >> N >> D;
		double v,f,r;
		for(int j=0; j<N; j++) {
			cin >> v >> f >> r;
			if( v*f/r >= D) cnt++;
		}	
		cout << cnt << endl;
	}
	return 0;
}
