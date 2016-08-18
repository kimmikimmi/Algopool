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

int T;
vector<string> expressions;
vector<double > double_bag;
void input(std::istream& pin) {

	string ttt;
	string temp;
	getline(std::cin, ttt);
	T = ttt[0] - '0';
	double d;
	for(int i=0; i<T; i++) {
		cin >> d;
		  std::getline (std::cin,temp);
		  expressions.push_back(temp);
		  double_bag.push_back(d);
	}

}

double calculate(double d, string _str) {
	
	double answer = d;
	for(auto& ch : _str) {
		if(ch == '@') answer *=3;
		if(ch == '%') answer += 5;
		if(ch == '#') answer -= 7;
	}	

	return answer;
}

int main() {
	input(cin);
	for(int i=0; i<T; i++) {
		printf("%.2f \n", calculate(double_bag[i], expressions[i]));
	}
	return 0;
}
