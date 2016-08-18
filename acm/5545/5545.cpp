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
int A,B;
int C;
vector<int> cal_topping;

void input(std::istream& pin) {
	pin >> N;
	pin >> A >> B;
	pin >> C;
	for(int i=0; i<N; i++) {
		int tmp;
		pin >> tmp;
		cal_topping.push_back(tmp);
	}
}

int method() {
	double total_price = A;
	double total_cal = C;
	double tmp_sol;
	sort(cal_topping.rbegin(), cal_topping.rend());
	for(auto& it : cal_topping) {
		tmp_sol = total_cal/total_price;
		total_cal += it;
		total_price += B;
		if(total_cal/total_price < tmp_sol) return tmp_sol;
	}	
	return 0;
}

int main() {
	input(cin);
	cout << method() << endl;

	return 0;
}
