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
int n;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> n;
	int score_c = 100;
	int score_s = 100;
	int c,s;
	for(int i=0; i<n; i++) {
		cin >> c >> s;
		if(c > s) {
			score_s -= c;
		} else if( c < s) {
			score_c -= s;
		}
	}
	cout << score_c << endl << score_s;
	return 0;
}
