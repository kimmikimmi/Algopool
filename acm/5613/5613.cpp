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

int method() {
	return 0;
}

int main() {
	string cal_buf;
	int result = 0;
	char oper;
	for(int i=0;; i++) {
		cin >> cal_buf;
		if(i==0) result = stoi(cal_buf);
		else {
			if(i%2 == 1) {
				oper = cal_buf[0];
				if(oper == '=') break;
			}
			else {
				int rh = stoi(cal_buf);
				switch(oper) {
					case '+':
						result += rh;
						break;
					case '-':
						result -= rh;
						break;
					case '*':
						result *= rh;
						break;
					case '/':
						result /= rh;
				}
			}
		}	
	}
	cout << result << endl;
	return 0;
}
