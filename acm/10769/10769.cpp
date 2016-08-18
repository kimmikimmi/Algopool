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

string sentence;

void input(std::istream& pin) {
	getline(pin, sentence);
}

int method(string& target) {
	int h_cnt = 0;
	int s_cnt = 0;
	for(int i=0; i<target.size()-2; i++) {
		if(target[i] == ':' && target[i+1] == '-') {
			if(target[i+2] == '(')  s_cnt++;
			if(target[i+2] == ')') h_cnt++;
		}
	}
	if(h_cnt == 0 && s_cnt == 0) cout << "none" << endl;
	else if( h_cnt == s_cnt) cout << "unsure" << endl;
	else if( h_cnt > s_cnt) cout << "happy" << endl;
	else
		cout << "sad" << endl;
	return 0;
}

int main() {
	input(cin);
	method(sentence);
	return 0;
}
