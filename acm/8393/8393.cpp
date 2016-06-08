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
int n;

void input(std::istream& pin) {
	pin >> n;
}

int method(int a) {

	

	return a*(a+1)/2;
}

int main() {
	input(cin);	
	cout << method(n) << endl;
	return 0;
}
