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

int month;
int day;

void input(std::istream& pin) {
	pin >> month >> day;
}

int method() {
	if(month < 2) cout << "Before" << endl;
	else if(month > 2) cout << "After" << endl;
	else {
		if(day <18 ) cout << "Before" << endl;
		else if(day > 18) cout << "After" << endl;
		else
			cout << "Special" << endl;
	}
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
