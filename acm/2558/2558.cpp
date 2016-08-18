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
int A,B;

void input(std::istream& pin) {
	pin >> A >> B;
}

int method() {
	cout << A+B << endl;
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
