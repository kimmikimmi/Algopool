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
	int a,b,c;
	for(int i=1; ; i++) {
		cin >> a >> b >> c;
		if(a == 0 &&
				b == 0 &&
					c == 0) break;

		cout << "Triangle #" << i << endl;
		if( (a>=c && b == -1) ||
			  	(b>=c && a == -1)) 
				cout << "Impossible." << endl;
		else if( a == -1) 
			printf("a = %.3f\n", sqrt(c*c - b*b));
		else if( b == -1)
			printf("b = %.3f\n", sqrt(c*c - a*a));
		else {		
			printf("c = %.3f\n", sqrt(a*a + b*b));
		}
		cout << endl;
	}
	return 0;
}
