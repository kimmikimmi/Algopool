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
int N;
string num;
void input(std::istream& pin) {
	pin >> N;
	pin >> num;
}

int method() {
	int sum = 0;
	for(auto& it : num) {
		sum += it-'0';
	}
	return sum;
}

int main() {
	input(cin);
	cout << method();
	return 0;
}
