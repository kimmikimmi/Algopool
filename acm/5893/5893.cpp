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

string bin_num;

void input(std::istream& pin) {
	pin >> bin_num;
}

string bin_add(string bin1, string bin2) {
	int carry = 0;
	string result = "";
	string r_bin1(bin1);
	string r_bin2(bin2);

  	copy(bin1.rbegin(), bin1.rend(), r_bin1.begin());
	copy(bin2.rbegin(), bin2.rend(), r_bin2.begin());
	r_bin2.append("0000");

	//cout << "b1 = " << r_bin1 << endl << "b2 = "  << r_bin2 << endl;
	int len = r_bin1.size();
	for(int i=0; i<len; i++) {
		int each_digit =  (r_bin1[i]-'0') + (r_bin2[i]-'0') + carry;
		if(each_digit > 1) {
		   each_digit %=2;
		   carry = 1;
		} else 
			carry = 0;
		result += (char)(each_digit + '0');		
	}
	
	//cout << "an = " << result << endl;
	//result += "0";
	if(carry == 1) result.append("1");
	string r_result(result);
	copy(result.rbegin(), result.rend(), r_result.begin());	
	//cout << r_result << endl;
		
	return r_result;
}

int main() {
	input(cin);
	string num1 = bin_num + "0000";
//	cout << num1 << " " << bin_num << endl;
	cout << bin_add(num1 , bin_num);
	return 0;
}
