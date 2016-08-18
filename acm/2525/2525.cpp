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

int A,B;
int C;
int rA,rB;
void input(std::istream& pin) {
	pin >> A >> B;
	pin >> C;
	rA = C/60;
	rB = C%60;
}

int method() {
	int carry = 0;
	int nA = 0, nB = 0;
	if(B + rB >= 60) {
	   nB = B + rB - 60;
	   nA = A + 1 + rA;
	   if(nA >= 24) nA -= 24;
	} else {
		nB = B + rB;
		nA = A + rA;
		if(nA >= 24) nA -= 24;
	}
	
			 cout << nA << " " << nB ;   
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
