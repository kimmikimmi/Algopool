#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int T;

vector<int> n_bag;
vector<int> k_bag;

void input(istream& in) {
}

void method(int n, int k) {
	
}

int main() {
	cin >> T;
	int cnt;
	int N, K;
	int tmp;
	for(int i=0; i<T; i++) {
	   cin >> N >> K;
	   cnt = 0;
		for(int i=0; i<N; i++) {
			cin >> tmp;
			cnt += tmp/K;
		}
		cout << cnt << endl;
	}
		return 0;

}
