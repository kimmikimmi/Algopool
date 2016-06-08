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
vector<int> int_bag;
void input(std::istream& pin) {
	pin >> T;
	int N;
	int tmp;
	for(int i=0; i<T; i++) {
		pin >> N;
		int sum = 0;
		for(int j=0; j<N; j++) {
			pin >> tmp;
			sum += tmp;
		}
		cout << sum << endl;
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	return 0;
}
