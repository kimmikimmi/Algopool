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

int a;

void input(std::istream& pin) {
	pin >> a;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	int sum = 0;
	int dif = 1000 - a;
	sum += dif/500;
	dif %= 500;
	sum += dif/100;
	dif %= 100;
	sum += dif/50;
	dif %= 50;
	sum += dif/10;
	dif %= 10;
	sum += dif/5;
	dif %= 5;
	sum += dif;
	cout << sum;
	return 0;
}
