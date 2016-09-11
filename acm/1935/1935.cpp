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

int N;
string expr;
vector<double> mapper;

stack<string> s;

void input(std::istream& pin) {
	pin >> N;
	pin >> expr;
	
	mapper.assign(26, -1);
	for(int i=0; i<N; i++) {
		pin >> mapper[i];
	}	
}

double calculate(char& op, stack<string>& cal_stk) {
	double cal_val = 0;
	double lh, rh;
	if(cal_stk.size() < 2) return 0;
	
	rh = stod(cal_stk.top());
	cal_stk.pop();
	
	lh = stod(cal_stk.top());
    cal_stk.pop();
/*
	cout << "op = " << op << endl;
	cout << "size of stack is " << cal_stk.size() << endl;
	cout << "lh , rh = " << lh << " " << rh << endl;
*/	
	if(op == '+') 
		cal_val = lh + rh;
	else if(op == '-') 
			cal_val = lh - rh; 
	else if(op == '*')
			cal_val = lh * rh;			
	else if(op == '/')
			cal_val = lh / rh;

	s.push(to_string(cal_val));
//	cout << to_string(cal_val) << " is inserted to stack" << endl;	
	return cal_val;
}

int main() {
	input(cin);
	double tmp_ans = 0;
	for(auto& it : expr) {
		if(it >= 'A' && it <= 'Z') { 
//			cout << mapper[it-'A'] << " is inserted to stack " << endl;
			s.push(to_string(mapper[it-'A']));
		}
		else {
			tmp_ans = calculate(it, s);
		}
	}
	printf("%.2f", tmp_ans);
	return 0;
}
