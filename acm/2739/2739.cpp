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
void input(std::istream& pin) {
	pin >> N;
}

int method() {
	for(int i=1; i<10; i++) 
		cout << N << " * " << i << " = " << N*i << endl;
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
