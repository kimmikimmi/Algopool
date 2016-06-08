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
	vector<int> int_bag(3);
	int a,b,c;
	cin >> int_bag[0] >> int_bag[1] >> int_bag[2];

	sort(int_bag.begin(), int_bag.end());
	cout << int_bag[1] << endl;
	
	return 0;
}
