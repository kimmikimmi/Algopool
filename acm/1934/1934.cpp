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
int t;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> t;
	int a,b;
	for(int i=0; i<t; i++) {
		cin >> a >> b;
		int gcd = __gcd(a,b);
		cout << a*b/gcd << endl;
	}
	return 0;
}
