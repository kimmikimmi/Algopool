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

int N, K;

void input(std::istream& pin) {
	pin >> N >> K;
}

long long method(int a, int b) {
	if(b ==0 || a==1 || b==a) 
		return 1;
	else 
		return method(i
	return sol;
}

int main() {
	input(cin);
	cout << method(N,K) << endl;
	return 0;
}
