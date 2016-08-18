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

int T;
void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> T;
	int a,b;
	for(int i=0; i<T; i++) {
		cin >> a >> b;
		cout << "You get " << a/b << " piece(s) and your dad gets " << a%b <<
			" piece(s)." << endl;
	}
	return 0;
}
