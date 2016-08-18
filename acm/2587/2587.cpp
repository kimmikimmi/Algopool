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
vector<int> my_vec(5);

void input(std::istream& pin) {
	for(int i=0; i<5; i++) {
		int tmp;
		pin >> tmp;
		my_vec[i] = tmp;
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	sort(my_vec.begin(), my_vec.end());
	int sum = 0;
	for(auto& it : my_vec) {
	   sum += it;
	}
	cout << sum/5 << endl <<my_vec[2] << endl;
		
	return 0;
}
