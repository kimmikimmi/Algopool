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

string word;

void input(std::istream& pin) {
	pin >> word;
}

int method(string& _str) {
	int	cnt_joi = 0; int cnt_ioi = 0;
	int len = _str.size();
	for(int i=0; i<len-2; i++) {
		if(_str[i]=='J' && _str[i+1] == 'O'
					&& _str[i+2] == 'I') cnt_joi++;
		else if(_str[i] == 'I' && _str[i+1] =='O' 
					&& _str[i+2] == 'I') cnt_ioi++;
	}
	cout << cnt_joi << endl << cnt_ioi;	
	return 0;
}

int main() {
	input(cin);
	method(word);
	return 0;
}
