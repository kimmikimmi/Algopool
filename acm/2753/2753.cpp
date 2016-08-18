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
	if((year%4 == 0 && year%100 != 0) || year %400 == 0) cout << 1 << endl;
	
	else 
		cout << 0 << endl;
	return 0;
}
