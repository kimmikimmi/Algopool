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

int method(int N) {
	for(int i=0; i<2*N-1; i++) {
		for(int j=0; j<2*N-1; j++) {
			if((i <= j) && (i + j <= 2*N-2)) cout << "*";
			else if( (i >=j) && (i +j >= 2*N-2)) cout  << "*";
			else
				cout << " ";
		}
		cout << endl;
	}	
	return 0;
}

int main() {
	input(cin);
	method(N);
	return 0;
}
