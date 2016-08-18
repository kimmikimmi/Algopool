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

int method() {
	string tmp = "";
	for(int i=0; i<N; i++) {
		for(int j=0; j<i+1; j++) 
		   tmp += "*";
		//for(int j=0; j<i+1; j++) 
		//	tmp += "*";
		cout << tmp << endl;
		tmp = "";
	}
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
