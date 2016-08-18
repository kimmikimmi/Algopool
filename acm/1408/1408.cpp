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

string t1;
string t2;

void input(std::istream& pin) {
	pin >> t1
		>> t2;
}

int method() {
	string hr1 = t1.substr(0,2);
	string hr2 = t2.substr(0,2);

	string m1 = t1.substr(3,2);
	string m2 = t2.substr(3,2);

	string s1 = t1.substr(6,2);
	string s2 = t2.substr(6,2);

	int i_hr1 = stoi(hr1);
	int i_hr2 = stoi(hr2);

	int i_m1 = stoi(m1);
	int i_m2 = stoi(m2);
	
	int i_s1 = stoi(s1);
	int i_s2 = stoi(s2);
	
	int r_h, r_m, r_s;
	
	r_s = i_s2 - i_s1;
	if(r_s < 0) {
		r_s += 60;
		i_m2--;
	}	

	r_m = i_m2 - i_m1;
    if(r_m < 0) {
		r_m += 60;
		i_hr2--; 
	}	

	r_h = i_hr2 - i_hr1;

	if(r_h < 0) r_h += 24;

	string hr, m, sec;
	hr = to_string(r_h);
	m = to_string(r_m);
	sec = to_string(r_s);
	if(hr.size() == 1) hr = "0" + hr;
	if(m.size() == 1) m = "0" + m;
	if(sec.size() == 1) sec = "0" + sec;
	hr = hr + ":" + m + ":" + sec;
	cout << hr << endl;	
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
