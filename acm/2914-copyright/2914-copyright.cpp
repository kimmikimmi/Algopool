#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int A;
int I;

void input(istream& in) {
	in >> A >> I;
}

void method() {
	int ans = A * (I-1) + 1;
	cout << ans << endl; 
}

int main() {
	input(cin);
	method();
	return 0;
}
