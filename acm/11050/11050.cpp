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
int binomialCoeff(int n, int k) {
	if(k==0 || k ==n)
		return 1;
	return binomialCoeff(n-1,k-1) + binomialCoeff(n-1, k);
}
int a,b;

void input(std::istream& pin) {
	pin >> a >> b;	
}

int method() {
	input(cin);
	cout << binomialCoeff(abb);
	return 0;
}

int main() {
	method();
	return 0;
}
