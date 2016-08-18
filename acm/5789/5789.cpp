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
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		string str_buf ;
		cin >> str_buf;
		if(str_buf[str_buf.size()/2] == str_buf[str_buf.size()/2-1])
			cout << "Do-it" << endl;
		else
			cout << "Do-it-Not" << endl;
	}
	return 0;
}
