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
	string a,b;
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> a >> b;
		cout << "Distances: " ;
		for(int i=0; i<a.size(); i++) {
			if(b[i] >= a[i]) cout << b[i]-a[i] << " ";
			else
				cout << b[i]+26 - a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
