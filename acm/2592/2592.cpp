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

vector<int> my_vec;

void input(std::istream& pin) {
	int tmp;
	for(int i=0; i<10; i++) {
		pin >> tmp;
		my_vec.push_back(tmp);
	}	
}

int method() {
	sort(my_vec.begin(), my_vec.end());
	int expect = 0;
	int sum = 0;

	for(auto& it : my_vec) {
		sum += it;
	}
	expect = sum / 10;
	vector<pair<int, int>> true_vec;
	for(int i=0; i<my_vec.size()-1; i++) {
		if(my_vec[i] != my_vec[i+1]) {
			pair<int , int> p1(my_vec[i], 1);
			true_vec.push_back(p1);
		}
	}
	for(auto& it : my_vec) {
		for(int i=0; i<true_vec.size(); i++) {
			if(it == true_vec[i].first) true_vec[i].second++; 
		}
	}
	sort(true_vec.begin(), true_vec.end(), [](pair<int, int> p1, pair<int, int> p2) { return p1.second > p2.second;});
	cout << expect  << endl << true_vec[0].first;
	return 0;
}

int main() {
	input(cin);
	method();	
	return 0;
}
