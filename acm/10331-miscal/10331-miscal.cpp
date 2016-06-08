#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <stack>
using namespace std;

string expr;
int ans;
stack<char> s;

void input(istream& in) {
	in >> expr;
	in >> ans;
}

int cal_left_first(string _expr) {
	int result = 0;
	for(auto& it : _expr) {
		int cur_num = it -'0';
		if((cur_num >=0) && (cur_num <=9)) {
			// do something..
			if(!s.empty()) {
				if(s.top() == '+' ) 
					result += cur_num;
				else 
					result *= cur_num;
				s.pop();
			} else 
				result += cur_num;
		} else {
			s.push(it);
		}

	}
	return result;

}

int cal_mul_first(string _expr) {
	int result = 0;
	stack<int> num_bag;
	stack<char> rules;

	for(auto& it : _expr) {
		int cur_num = it - '0';

		if((cur_num >= 0) && (cur_num <= 9)) {
			if(num_bag.empty()) num_bag.push(cur_num);
			else 
				if(rules.top() == '*') {
					int tmp;
					tmp = cur_num * num_bag.top();
					rules.pop();
					num_bag.pop();
					num_bag.push(tmp);
				} else 
					num_bag.push(cur_num);
		} else {
			rules.push(it);
		}
	}
	int size = num_bag.size();
	for(int i=0; i<size; i++) {
		result += num_bag.top();
		num_bag.pop();
	}	

	return result;
}

int main() {
	input(cin);
	int result_left = cal_left_first(expr);
	int result_mul = cal_mul_first(expr);
	
	if(result_left == result_mul && result_left == ans) cout << "U" << endl;
	else if(result_left == ans) cout << "L" << endl;
	else if(result_mul == ans) cout << "M" << endl;
	else
		cout << "I" << endl;
	return 0;
}
