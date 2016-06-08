#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <stdio.h>

using namespace std;

int N;
vector<pair<int, int>> pairs;

void input(istream& in) {
	in >> N;
	int x, y;
	for(int i=0; i<N; i++) {
		in >> x >> y;
		pair<int, int> p(x,y);
		pairs.push_back(p);
	}
}

void method() {

}

int main() {
	scanf("%d", &N);
	int x,y;
	for(int i=0; i<N; i++) {
		scanf("%d %d", &x, &y);
		pair<int, int> p(x,y);
		pairs.push_back(p);
	}

	sort(pairs.begin(), pairs.end(), [](pair<int, int> p1, pair<int, int> p2) {
			if(p1.second == p2.second) return p1.first < p2.first;
			return p1.second < p2.second;
			});
	for(auto& it : pairs) 
		printf("%d %d\n", it.first, it.second);

	return 0;
}