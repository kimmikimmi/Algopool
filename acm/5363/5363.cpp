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
int N;
vector<string> statements;
void input(std::istream& pin) {
	pin >> N;
	string statement;
	while(getline(pin, statement)) 
		statements.push_back(statement);
	
}

int method() {
	return 0;
}

int main() {
	input(cin);
	for(int i=1; i<statements.size(); i++) {
		stringstream s(statements[i]);
		string tmp1, tmp2;
		s >> tmp1 >> tmp2;
		statements[i] += " " + tmp1 + " " + tmp2;
		statements[i].erase(0,tmp1.size() + tmp2.size()+2); 
		cout << statements[i] << endl;
	}
	return 0;
}
