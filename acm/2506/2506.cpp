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
vector<int> table;

void input(std::istream& pin) {
	pin >> N;
	int tmp;
	for(int i=0; i<N; i++) {
		pin >> tmp;
		table.push_back(tmp);
	}
}

int method() {
	int sum = 0;
	int point = 0;
	for(int i=0; i<N; i++) {
		if(table[i] == 1) {
			point++;
		} else 
			point = 0;
		sum += point;
	}
	return sum;
}

int main() {
	input(cin);
	cout << method() << endl;
	return 0;
}
