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
	int n;
	cin >> n;
	int cnt = 0;
	int tmp;
	for(int i=0; i<5; i++) {
		cin >> tmp;
		if(tmp == n) cnt++;

	}
	cout << cnt;
	return 0;
}
