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
		for(int i=0; i<M; i++) {
			cin >> a >> b;
		}
		cout << N-1 << endl;
	}
	return 0;
}
