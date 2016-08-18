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

string num1;
string num2;

void input(std::istream& pin) {
	pin >> num1 >> num2;	
}

int method(string n1, string n2) {
	int i_n1 = stoi(n1);
	int i_n2 = stoi(n2);
	
	int three = i_n1 * (n2[2] - '0');
	int four = i_n1 * (n2[1] - '0');
	int five = i_n1 * (n2[0] - '0');
	int sum = three + four*10 + five*100;
	cout << three << endl;
	cout << four << endl;
	cout << five << endl;
	cout << sum << endl;

	return 0;
}

int main() {
	input(cin);
	method(num1, num2);
	return 0;
}
