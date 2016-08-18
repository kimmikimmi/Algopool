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

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int r,w,l;
	 r = 1;
	
	for(int i=1;; i++) {
		cin >> r;
		if(r == 0) break;
		cin >> w >> l;
		cout << "Pizza " << i ;
		if(w*w + l*l <= (2*r)*(2*r)) cout << " fits on the table." << endl;
		else
			cout << " does not fit on the table." << endl; 

	}

	return 0;
}
