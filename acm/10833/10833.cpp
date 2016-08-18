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
	int t;
	cin >> t;
	int sum = 0;
	for(int i=0; i<t; i++) {
		int stu,app;
		cin >> stu >> app;
		int tmp = app% stu;
		sum += tmp;
		
	}
	cout << sum << endl;
	return 0;
}
