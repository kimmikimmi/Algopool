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

#define team pair<int, int>

using namespace std;
int N,S,R;

vector<team> teams;

void input(std::istream& pin) {
	pin >> N >> S >> R;
	
	team t;
	int tmp;
	
	for(int i=0; i<N; i++) 
		teams.push_back(make_pair(i, 1)); 	
	
	for(int i=0; i<S; i++) {
		pin >> tmp;
		teams[tmp-1].second--;	
	}

	for(int i=0; i<R; i++) {
		pin >> tmp;
		teams[tmp-1].second++;
	}
	
}

int method() {
	return 0;
}

int main() {
	input(cin);

	for(int i=0; i<teams.size(); i++) {
		if(teams[i].second == 0) {
			if(i!=0 && teams[i-1].second == 2) {
				teams[i].second = 1;
				teams[i-1].second = 1;
			} else if(i != teams.size()-1 && teams[i+1].second == 2) {
				teams[i].second = 1;
				teams[i+1].second = 1;
			}
		}
	}
	int cnt = 0;
	for(auto& it : teams) {
		if(it.second == 0) cnt ++;
	}
	cout << cnt << endl;
	return 0;
}
