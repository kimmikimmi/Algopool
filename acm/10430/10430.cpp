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
int a, b, c;
void input(std::istream& pin) {
	pin >> a >> b >> c;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	cout << (a+b)%c << endl;
	cout << ((a%c) + (b%c))%c << endl;
	cout << (a*b)%c << endl;
	cout << ((a%c) * (b%c))%c << endl;
	return 0;
}
