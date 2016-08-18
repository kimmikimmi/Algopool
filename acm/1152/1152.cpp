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
#include <sstream>
using namespace std;

string _str;
void input(std::istream& pin) {
	getline(pin, _str);
}

int method() {
	return 0;
}

int main() {
	input(cin);
	stringstream s(_str);
	int cnt = 0;
	string tmp;
	//cout << _str << endl;
	while( s >> tmp) 
		cnt++;
	//cout << cnt << endl;

	return 0;
}
