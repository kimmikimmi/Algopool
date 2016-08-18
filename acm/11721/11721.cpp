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
string target_str;
void input(std::istream& pin) {
	pin >> target_str;
}

int method() {
	int len = target_str.size();
	int loop = len%10 == 0 ? len/10 : len/10 + 1;
	for(int i=0; i<loop; i++) {
		cout << target_str.substr(i*10, 10) << endl;
	}	

	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
