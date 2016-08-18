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
int a1, a2, a3;

void input(std::istream& pin) {
	pin >> a1 >> a2 >> a3;	
}

int method() {
	return 0;
}

int main() {
	while(true) {
		cin >> a1 >> a2 >> a3;
		if(a1 == 0 && a2 == 0 && a3 == 0) break;
		if(a2 - a1 == a3 - a2) cout << "AP " << a3 + a2 - a1 << endl;
		else 
			cout << "GP " << a3*a2/a1 << endl;
	}
	return 0;

}
