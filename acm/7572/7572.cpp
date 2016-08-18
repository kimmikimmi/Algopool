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
	int year;
	cin >> year;
	int a = (year + 6) % 10 ;
	int b = (year + 8) % 12 ;
	char c = 'A' + b;
	cout << c << a << endl;
	return 0;
}
