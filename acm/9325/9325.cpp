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
	cin >> T;
	for(int i=0; i<T; i++) {
		int sum = 0;
		int s;
		cin >> s;
		int p,q;
		int n;
		cin >> n;
		for(int j=0; j<n; j++) {
			cin >> p >> q;
			s += p*q;
		}
		cout << s << endl;

	}
	return 0;
}
