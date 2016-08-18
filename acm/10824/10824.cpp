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
vector<string> Ns;

void input(std::istream& pin) {
	string tmp1;
	string tmp2;
	for(int i=0; i<2; i++) {
		cin >> tmp1 >> tmp2;
		Ns.push_back(tmp1 + tmp2);
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	long long sum = 0;
	for(auto& it : Ns) {
		sum += stoll(it);
	}
	cout << sum;
		
	return 0;
}
