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

int K;

void input(std::istream& pin) {
	pin >> K;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	int N;
	for(int i=0; i<K; i++) {
		cin >> N;
		vector<int> tmp_bag(N);
		for(int j=0; j<N; j++) {
			cin >> tmp_bag[j];
		}
		sort(tmp_bag.begin(), tmp_bag.end());
		int l_gap = 0;
		for(int i=0; i<N-1; i++) {
			int gap = tmp_bag[i+1] - tmp_bag[i];
			if(l_gap < gap) l_gap = gap;
		}
		cout << "Class " << i+1 << endl;
		cout << "MAX " << tmp_bag[N-1] << ", Min " << tmp_bag[0] << ", Largest gap " <<
			l_gap << endl;
	}
	return 0;
}
