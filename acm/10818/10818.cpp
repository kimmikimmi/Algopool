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
vector<int> bag;

void input(std::istream& pin) {
	pin >> N;
	bag.assign(N, 0);
	for(int i=0; i<N; i++) 
		pin >> bag[i];
}

int method() {
	return 0;
}

int main() {
	input(cin);
	sort(bag.begin(), bag.end());
	cout << bag[0] << " " << bag[bag.size()-1];	
	return 0;
}
