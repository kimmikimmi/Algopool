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
int X;

void input(std::istream& pin) {
	pin >> X;
}

int method(int n) {
	for(int i=1; ;i++) {
		if(i*(i+1) >= 2*n) {
			int k = i*(i+1)/2 - n;
			//1cout << "i = " << i << " n = " << n << " k = " << k << endl; 

		    if(i % 2 == 0)cout << i-k << "/" << k+1 << endl;
			else
				cout << k + 1 << "/" << i-k << endl;
			break;	
		}
	}
	return 0;
}

int main() {
	input(cin);
	method(X);
	return 0;
}
