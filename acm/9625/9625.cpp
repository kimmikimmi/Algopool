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
int K;
int a_set[46];
int b_set[46];
void input(std::istream& pin) {
	pin >> K;
	for(int i=0; i<46; i++) {
		a_set[i] = -1;
		b_set[i] = -1;
	}
}
int a(int n);
int b(int n) {
	if(b_set[n] != -1) return b_set[n];
	if(n == 0) return 0;
	return b_set[n] = a(n-1) + b(n-1);
}

int a(int n) {
	if(a_set[n] != -1) return a_set[n];
	if(n==0) return 1;
	return a_set[n] = b(n-1);
}

int main() {
	input(cin);
	cout << a(K)  << " " << b(K);
	return 0;
}
