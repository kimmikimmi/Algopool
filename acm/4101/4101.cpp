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
	int head = 1;
	int tail = 1;

	while(true) {
		cin >> head >> tail;
		if(head == 0 && tail == 0) break;
		if(head > tail) cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	
	return 0;
}
