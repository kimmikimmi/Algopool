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

int n;
vector<string> str_bag;
void input(std::istream& pin) {
	pin >> n;
	str_bag.assign(n, "");
	for(int i=0; i<n; i++) 
		pin >> str_bag[i];
}

string method(string& input_str) {
	string dest_str = "";
	for(auto& it : input_str) {
		if(it == 'Z') dest_str += 'A';
	    else 
			dest_str += it + 1;
	}
	return dest_str;
}

int main() {
	input(cin);

	for(int i=0; i<n; i++) {
		cout << "String #" << i+1 << endl;
		cout << method(str_bag[i]) << endl << endl;
	}
	return 0;
}
