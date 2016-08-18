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


void input(std::istream& pin) {

}

int method() {
	return 0;
}
using namespace std;
int main() {
	int n;
	cin >> n;
	string stars = "";
	for(int i=1; i<=n; i++) {
	   stars = "";	
		for(int j=0; j<i; j++) {
			stars += '*';
		}
		cout << stars << endl;
	}
	for(int i=n-1; i>=1; i--) {
		stars = "";
		for(int j=0; j<i; j++) {
			stars += '*';
		}
		cout << stars << endl;
	}
	return 0;
}
