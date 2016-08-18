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

string _str;

void input(std::istream& pin) {
	pin >> _str;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	stack<char> s;
	int cal = 0;
	for(auto& it : _str) {
		if(s.empty()) {
			s.push(it);
			cal += 10;
	     }	else {
			if(s.top() == it ) {
				s.push(it);
				cal += 5;
			} else {
				s.push(it);
				cal += 10;
			}	

		}	
			
	}
	cout << cal << endl;
	return 0;
}
