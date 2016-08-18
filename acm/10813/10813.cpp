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
typedef int ball;

int N;
int M;

vector<pair<int, int>> pairs;
vector<ball> baskets;

void init_basket(int& n) {
	baskets.assign(n+1, 0);
	for(int i=1; i<n+1; i++) 
		baskets[i] = i;
}
void input(std::istream& pin) {
	pin >> N >> M;
	int a,b;
	
	init_basket(N);

	for(int i=0; i<M; i++) {
		pin >> a >> b;
		pairs.push_back(make_pair(a,b));
	}
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int method() {
	for(auto& it : pairs) {
		swap(baskets[it.first], baskets[it.second]);
	}
	return 0;
}

int main() {
	input(cin);
	method();
	for(auto it = baskets.begin()+1; it != baskets.end(); ++it)
		cout << *it << " ";
	return 0;
}
