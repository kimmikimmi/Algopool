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


void input(std::istream& pin) {

}

int method(string in_str) {
	int a;
	if(in_str ==  "black") 
			a = 0;
	else if( in_str == "brown")
			a = 1;	
	else if (in_str == "red")
			a = 2;	
    else if (in_str == "orange")
			a = 3;	
	else if (in_str == "yellow")
			a = 4;
	else if ( in_str == "green")
			a = 5;
	else if (in_str == "blue")
			a = 6;
	else if (in_str == "violet")
			a = 7;
	else if (in_str ==  "grey")
			a = 8;
	else if( in_str =="white")
			a = 9;
	return a;

}

int main() {
	string str_buf;
	vector<long long> mux;
	vector<int> val;
	for(int i=0; i<10; i++) {
		mux.push_back((long long)pow(10,i));
		val.push_back(i);
	}
	long long sum = 0;
	cin >> str_buf;
	sum += 10*val[method(str_buf)];
	cin >> str_buf;
	sum += val[method(str_buf)];
	cin >> str_buf;
	sum *= mux[method(str_buf)];
	cout << sum << endl;
	return 0;
}
