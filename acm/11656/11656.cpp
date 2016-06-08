#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

string S;
vector<string> prefix_vec;
void input(istream& in) {
	in >> S;
}


void method() {
	string prefix;
	for(auto it=S.begin(); it != S.end(); ++it) {
		prefix.assign(it, S.end());
		prefix_vec.push_back(prefix);
	}
}

int main() {
	input(cin);
	method();
	sort(prefix_vec.begin(), prefix_vec.end());
	for(auto& it : prefix_vec) cout << it << endl;
	return 0;
}
