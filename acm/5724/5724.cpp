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


vector<int> bag;

void input(std::istream& pin) {
	int tmp = 1;
	while(true) {
		pin >> tmp;
		if(tmp == 0) break;
		bag.push_back(tmp);
	}
}

int method(int& n) {
	return n*(n+1)*(2*n+1)/6;
}

int main() {
	input(cin);
	for(auto& it : bag)
		cout << method(it) << endl;
	return 0;
}
