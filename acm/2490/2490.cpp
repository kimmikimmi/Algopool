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
	int a,b,c,d;
	for(int i=0; i<3; i++) {
		cin >> a >> b >> c >> d;
		int ans = a + b + c + d;
		if(ans == 0) cout << "D" << endl;
		else if(ans == 1) cout << "C" << endl;
		else if(ans == 2) cout << "B" << endl;
		else if(ans == 3) cout << "A" << endl;
		else 
			cout << "E" << endl;
	}
	return 0;
}
