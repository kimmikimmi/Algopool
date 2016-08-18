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

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int r = 0;
	int e = 0;
	int c = 0;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> r >> e >> c;
		if( e - c > r ) cout << "advertise" << endl;
		else if( e - c == r) cout << "does not matter" << endl;
		else
			cout << "do not advertise" << endl;
	}
	return 0;
}
