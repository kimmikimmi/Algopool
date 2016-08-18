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

string expression;
void input(std::istream& pin) {
	string tmp_str;
	while(getline(cin, tmp_str)) {
		expression += tmp_str;
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);

	string acc = "";
	vector<string> bag;
	int str_size = expression.size();

	for(auto& it : expression) {
		if(it == ',' ) {
			bag.push_back(acc);
			acc = "";
		} else 
			acc += it;	
	}
	bag.push_back(acc);
	int sum = 0;
	for(auto& it : bag) sum += stoi(it);
	cout << sum;
	return 0;

}
