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

char decrypt(char& c) {
	if( c <= 'C') return (char)(c + 23);
	return (char)(c - 3);
}

string method() {
	
	string dec_msg = "";

	for(auto& it : word) 
		dec_msg += decrypt(it);
	
	return dec_msg;
	
}

int main() {
	input(cin);
	 cout <<method();
	
	return 0;
}
