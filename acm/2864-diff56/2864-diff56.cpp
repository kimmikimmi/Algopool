#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int A;
int B;

string a_str;
string b_str;

void input(istream& in) {
	in >> a_str >> b_str;
}

int makeBigger(string str) {
	vector<int> int_bag;
	int n = 0;
    for(auto& it : str) {
		if(it - '0' == 5) 
			int_bag.push_back(6);
		else 
			int_bag.push_back(it-'0');
	}
	for(int i=0; i<int_bag.size(); ++i) 
		n += int_bag[i]*pow(10,int_bag.size()-i-1);
	return n;
}

int makeSmaller(string str) {
	vector<int> int_bag;
	int n = 0;
	
	for(auto& it : str) {
		if(it - '0' == 6) 
			int_bag.push_back(5);
		else 
			int_bag.push_back(it-'0');
	}
	for(int i=0; i<int_bag.size(); ++i) {
		n += int_bag[i]*pow(10,int_bag.size()-i-1);
	}
	return n;
}

int method() {
	return makeBigger(a_str) + makeBigger(b_str);
}
int method2() {
	return makeSmaller(b_str) + makeSmaller(a_str);
}
int main() {
	input(cin);
	cout << method2() << " " << method()<< endl;

	return 0;
}
