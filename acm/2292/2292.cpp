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

int n;

void input(std::istream& pin) {
	pin >> n;
}

int method() {
	int index = 0;
	for(int i=0; ;i++){
	   if( n < 2 + 3*i*(i+1)) {
		   index = i;
		   break;
	   }
	}

	return index +1;
}

int main() {
	input(cin);
	cout << method();
	return 0;
}
