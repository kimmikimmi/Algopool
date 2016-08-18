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
vector<pair<int, int>> int_bag;

void input(std::istream& pin) {
	int t;
	for(int i=0; i<8; i++) {
		pin >> t;
		pair<int, int> p(i+1, t);
		int_bag.push_back(p);
	}
}

int method() {

	return 0;
}

int main() {
	input(cin);
	sort(int_bag.begin(), int_bag.end(), [](pair<int, int> p1, pair<int, int> p2) {
			return p1.second > p2.second;});
	sort(int_bag.begin(), int_bag.begin()+5, [](pair<int, int> p1, pair<int, int> p2) {
			return p1.first < p2.first;});
	int sum = 0;
	for(int i=0; i<5; i++) {
		sum += int_bag[i].second;
	}
	cout << sum << endl;
	for(int i=0; i<5; i++) cout << int_bag[i].first << " "; 
	return 0;
}
