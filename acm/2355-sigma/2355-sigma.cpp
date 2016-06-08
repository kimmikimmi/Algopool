#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

long long i; 
long long j;

void input(istream& in) {
	in >> i >> j;
}

void method() {
	long long ans = (abs(j-i)+1) / 2 * (j+i);
	cout << ans << endl;
}

int main() {
	input(cin);
	method();
	return 0;
}
