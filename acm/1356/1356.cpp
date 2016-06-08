#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <string>

using namespace std;

string N;

void input(istream& in) {
	in >> N;
}

bool isYujin(string str) {
	int result = 0;
	string prefix, postfix;
	int len = str.size();
	int pre_num ;
    int post_num ;

	for(int i=1; i<len; i++) { 
		prefix = str.substr(0,i);
		postfix = str.substr(i,len-i);
		pre_num = post_num = 1;

		for(auto& it : prefix) 
			pre_num *= it - '0';
		for(auto& it : postfix) 
			post_num *= it - '0';
		
		if(pre_num == post_num)
		   return true;	
	}

	return false;
}

int main() {
	input(cin);
	if(isYujin(N)) cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	return 0;
}
