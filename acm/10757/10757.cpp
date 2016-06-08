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
#include <stdlib.h>
using namespace std;

string a;
string b;

void input(std::istream& pin) {
	pin >> a >> b;
}

string method() {
	string answer = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int c = 0;
	int begin = a.size() > b.size() ? b.size() : a.size();
	string longer = a.size() > b.size() ? a : b;
	int len = longer.size();

	for(int i=0; i<begin; i++) {
		int tmp_num = c + (a[i]-'0') + (b[i]-'0');
		if(tmp_num >9) {
			tmp_num %= 10;
			c = 1;
		} else {
			c = 0;
		}
		answer += to_string(tmp_num);
	}
	
	for(int i=begin; i<len; i++) {
		int rest_num = c + (a[i] - '0');
		if(rest_num > 9) {
			rest_num %= 10;
			c = 1;
		} else 
			c = 0;
		answer += to_string(rest_num);
	}
	if(c == 1)
		answer += "1";

	reverse(answer.begin(), answer.end());
	return answer;
}

int main() {
	input(cin);
	cout <<method();
	return 0;
}
