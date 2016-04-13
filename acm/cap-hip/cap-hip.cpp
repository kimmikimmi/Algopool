#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string str;
stack<int> str_stk;
std::vector<char> sol_vec;

void input(istream& in) {
	in >> str;
}
void method() {
	int size = str.length()-1;
	sol_vec.push_back(str[0]);
	for(int i=1; i<size; i++) {
		if(str[i] == '-') sol_vec.push_back(str[i+1]);
	}

	for(auto k : sol_vec) cout << k ;
}

int main() {
	input(cin);
	method();
	return 0;
}
