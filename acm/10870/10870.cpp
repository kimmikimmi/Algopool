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

int fibo(int n) {
	if(n == 0 ) return 0;
	if(n== 1) return 1;
	
	return fibo(n-1) + fibo(n-2);
}

int main() {
	input(cin);
	cout << fibo(n);
	return 0;
}
