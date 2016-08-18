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
struct student {
	string name;
	int day;
	int month;
	int year;	
};

int n;
vector<student> b_day_list;

void input(std::istream& pin) {
	student s;
	pin >> n;
	b_day_list.assign(n, s);
	for(int i=0; i<n; i++) 
		pin >> b_day_list[i].name >> b_day_list[i].day 
			>> b_day_list[i].month >> b_day_list[i].year;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	string name;
	int day, month, year;
	sort(b_day_list.begin(), b_day_list.end(), [](student s1, student s2) {
		if(s1.year == s2.year) {
			if(s1.month == s2.month) 
				return s1.day > s2.day;
			return s1.month > s2.month;	
		} return s1.year > s2.year;});
		cout << b_day_list[0].name << endl;
		cout << b_day_list[n-1].name << endl;
	return 0;
}
