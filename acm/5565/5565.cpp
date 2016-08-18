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
	int sum;
	int nine = 0;
	int buf;
	cin >> sum;
	for(int i=0; i<9; i++) {
		cin >> buf;
		nine += buf;
	}
	cout << sum - nine << endl;
	return 0;
}
