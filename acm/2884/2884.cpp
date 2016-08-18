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

int H,M;
void input(std::istream& pin) {
	pin >> H >> M;
}

int method() {
	int cH, cM;
	if(M >= 45) {
		cH = H;
		cM = M-45;
	} else {
		cM = 60 + M - 45;
		if(H == 0) cH = 23;
		else 
			cH = H -1;
	}
	cout << cH << " " << cM << endl;
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
