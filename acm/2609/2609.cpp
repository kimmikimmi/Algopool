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
int lcm(int a, int b) {
	int tmp = std::__gcd(a, b);
	return tmp ? (a/ tmp*b) : 0;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << std::__gcd(a,b) << endl << lcm(a,b);
	return 0;
}
