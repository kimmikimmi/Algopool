#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int n;
int sol;
void input(istream& in) {
	in >> n;
}

void method() {

	for(int i=1; i<=n; i++) {
		
		if(i * (i+1) * (i+2) > n*6 ) {
			sol = i-1;
			break;
		}
		
	}
}

int main() {
	input(cin);
	method();
	cout << sol;
	return 0;
}
