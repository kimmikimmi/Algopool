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
long long Num;

void input(std::istream& pin) {
	pin >> Num;
}

bool method(int n) {
	return n && !(n &(n-1));
}

int main() {
	input(cin);
	if(method(Num)) cout << 1 <<endl;
	else 
		cout << 0 << endl;
	return 0;
}
