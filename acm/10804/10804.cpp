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

int N, M;
vector<int> baskets;
vector<pair<int, int>> pairs;

void input(std::istream& pin) {
		//pin >> N >> M;
		for(int i=0; i<20; i++) { 
			baskets.push_back(i+1);
		}
		for(int i=0; i<10; i++) {
			int a,b;
			pin >> a >> b;
			pairs.push_back(make_pair(a-1, b-1));
		}
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int method(int& a, int& b, vector<int>& bag) {
	int period = b - a + 1;
	period /= 2;
	for(int i=0; i<period; i++) {
		swap(bag[a+i], bag[b-i]);
	}
//	for(auto it : bag) cout << it << " " ;
//	cout << endl;
	return 0;
}

int main() {
	input(cin);
	for(auto& it : pairs) { 
		method(it.first, it.second, baskets);
	}
	for(auto& it : baskets)
		cout << it << " ";
	return 0;
}

