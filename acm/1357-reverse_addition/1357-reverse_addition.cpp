#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;


string x;
string y;

void input(istream& in) {
	in >> x >> y;
}

// string get_reverse_string(string& str) {
	
// 	string rev_str = string(str.rbegin(), str.rend());

// 	for(auto iter=rev_str.begin(); iter != rev_str.end(); iter++) {
// 		if(*iter == '0') {
// 			rev_str.erase(iter);
// 			--iter;
// 		}

// 	}
// 	return rev_str;
// }

int string_to_number(string str) {
	int target = 0;
	int tmp = 0;
	for( int i=str.size()-1; i>=0; i--) {
		tmp = str[i]-'0';
		target += (int)pow(10,i) * tmp;
		
	}
	return target;
}

void method() {

}

int main() {
	input(cin);
	
	int r_x = string_to_number(x);
	int r_y = string_to_number(y);
	string ans = to_string(r_x + r_y);
	cout << string_to_number(ans) << endl;
	
	return 0;
}
