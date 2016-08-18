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
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	int sol = a*a + b*b + c*c + d*d + e*e;
	sol %= 10;
	cout << sol;
	return 0;
}
