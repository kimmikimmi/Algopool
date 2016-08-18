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
string bin1;
string bin2;

void input(std::istream& pin) {
	pin >> bin1;
	pin >> bin2;
}

string add_binary(string n1, string n2) {
	
	string r_n1(n1);
	string r_n2(n2);	
	
	int carry = 0;

	copy(n1.rbegin(), n1.rend(), r_n1.begin());
	copy(n2.rbegin(), n2.rend(), r_n2.begin());
	
	int len_n1 = r_n1.size();
	int len_n2 = r_n2.size();

	if(len_n1 > len_n2) {
		for(int i=0; i<len_n1-len_n2; ++i) 
			r_n2 += "0";
	} else {
		for(int i=0; i<len_n2-len_n1; ++i) 
			r_n1 += "0";
	}
	
	len_n1 = r_n1.size();
	string result_r_str = "";
	for(int i=0; i<len_n1; i++) {
		int digit = (r_n1[i] - '0') + (r_n2[i] - '0') + carry;
		if( digit > 1) {
			carry = 1;
			digit %= 2;
		}
		result_r_str += (char)(digit + '0');	
	}
	string result_str(result_r_str);
	copy(result_r_str.rbegin(), result_r_str.rend(), result_str.begin());
	return result_str;
}

int main() {
	input(cin);
	cout << add_binary(bin1, bin2);
	
	return 0;
}
