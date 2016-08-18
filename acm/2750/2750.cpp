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
vector<int> array_bag;

void input(std::istream& pin) {
	pin >> N; 
	array_bag.assign(N, 0);
	int tmp;
	for(int i=0; i<N; i++) {
		pin >> tmp;
		array_bag[i] = tmp;
	}	
		
}

int method() {
	sort(array_bag.begin(), array_bag.end());
	return 0;
}

int main() {
	input(cin);
	method();
	for(auto& it : array_bag) 
		cout << it << endl;
	return 0;
}
