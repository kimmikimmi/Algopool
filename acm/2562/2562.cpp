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
	int index = 0; 
	int value = 0;
	for(int i=0; i<9; i++) {
		int tmp;
		cin >> tmp;
		if(value < tmp) {
			value = tmp;
			index = i+1;
		}
	}
	cout << value << endl << index;
	return 0;
}
