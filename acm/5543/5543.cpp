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
	int c_b = 2020;
	int c_d = 2020; 
	for(int i=0; i<3; i++) {
		int tmp;
		cin >> tmp;
		if(tmp < c_b) c_b = tmp; 
	}
	for(int i=0; i<2; i++) {
		int tmp2;
		cin >> tmp2;
		if(tmp2 < c_d) c_d = tmp2;
	}
	cout << c_b  +  c_d - 50  << endl;
	return 0;
}
