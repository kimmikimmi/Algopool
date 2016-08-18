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


int e, f, c;
void input(std::istream& pin) {
	pin >> e >> f >> c;
}

int method() {
	int sol = 0;
	int rest = 0;
	int tmp = e + f;
	while ( tmp >= c) {
		rest = tmp%c;
		tmp /= c;
		sol += tmp;
		tmp += rest;
		//cout  << "Rest = " << rest<< "sol = " << sol << endl;
		
	}	
	return sol;
}

int main() {
	input(cin);
	cout << method() << endl;
	return 0;
}
