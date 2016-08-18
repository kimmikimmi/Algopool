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
#include <sstream>

using namespace std;

vector<string> expressions;

void input(std::istream& pin) {
	
}

int method() {
	return 0;
}

int main() {
	string tmp_str;
	
	for(int i=1; ;i++) {
			
		getline(cin, tmp_str);
		stringstream ss(tmp_str);
		string ls, rs, oper;
		ss >> ls >> oper >> rs;
		if(oper == "E") break;
		bool value;
		if(oper == "!=") {
			if(ls != rs) value = true;
		    else
				value = false;	
		} else if(oper == "==") {
			if(ls == rs) value = true;
			else 
				value = false;
		} else if(oper == ">") {
			if(stoi(ls) > stoi(rs)) value = true;
			else
				value = false;
		} else if(oper == ">=") {
			if(stoi(ls) >= stoi(rs)) value = true;
			else
				value = false;
		} else if(oper == "<") {
			if(stoi(ls) < stoi(rs)) value = true;
			else
				value = false;
		} else {
			if(stoi(ls) <= stoi(rs)) value = true;
			else
				value = false;
		}
		if(value)
			cout << "Case " << i << ": true" << endl;  
		else
			cout << "Case " << i << ": false" << endl;  
	}
	return 0;
}
