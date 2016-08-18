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
void input(std::istream& pin) {
	
}

int method() {
	return 0;
}

int main() {
	scanf("%d", &N);
	vector<int> int_bag(N);
	for(int i=0; i<N; i++) {
		int tmp;
		scanf("%d", &tmp);
		int_bag[i] = tmp;
	}
	sort(int_bag.begin(), int_bag.end());
	for(auto& it : int_bag) 
		printf("%d \n", it);
	return 0;
}
