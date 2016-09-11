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

int N,M;

vector<int> left_sides;
vector<int> right_sides;

void input(std::istream& pin) {
	pin >> N >> M;
	
	int pos;
	for(int i=0; i<N; i++) {
		pin >> pos;
		if(pos < 0) 
			left_sides.push_back(-pos);
		else 
			right_sides.push_back(pos);
	}
}

int get_steps(vector<int>& side, int& len) {
	int steps = 0;

	for(int i=0; i<len; i=i+M) { 
		steps += side[i]*2;
//		cout << " side[i] = " << side[i]  << " steps = " << steps << endl;
	}
	
	return steps;
}

int get_waste_step(vector<int>& left, vector<int>& right) {
	if(right.empty()) return left[0];
	if(left.empty()) return right[0];

	return left[0] > right[0] ? left[0] : right[0];
}

int main() {
	input(cin);

	sort(left_sides.rbegin(), left_sides.rend());
	sort(right_sides.rbegin(), right_sides.rend());

	int left_len = left_sides.size();
	int right_len = right_sides.size();

//	cout << waste_step << endl;
	cout << get_steps(left_sides, left_len) 
      + get_steps(right_sides, right_len) 
	  - get_waste_step(left_sides, right_sides) << endl;
	
	return 0;
}
