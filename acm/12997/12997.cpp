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
int r,c;
vector<pair<int,int>> winners;
vector<pair<int,int>> winners2;
int main() {
	cin >> N;
	
	winners.assign(10001, make_pair(0,-1));
	winners2.assign(1001, make_pair(0,-1));
	for(int i=0; i<N; i++) {
		cin >> r >> c;
		if(winners[r].second < c) {
			winners[r].second = c;
			winners[r].first = i+1;
		}	
		if(winners2[c].second < r) {
			winners2[c].second = r;
			winners2[c].first = i+1;
		}
	}
	vector<pair<int, pair<int,int>>> ans_vec;
	vector<pair<int, pair<int,int>>> ans_vec2;
	for(int i=0; i<10001; i++) {
		if(winners[i].second != -1) 
			ans_vec.push_back(make_pair(winners[i].first, make_pair(i, winners[i].second)));
		if(winners2[i].second != -1) 
			ans_vec2.push_back(make_pair(winners2[i].first, make_pair(i, winners2[i].second)));
	}
	// sort..
	//
	int my_max = -1;
	vector<int> ans;
	cout << endl;
	for(int i=ans_vec2.size()-1; i>=0; i--) {
		if(ans_vec2[i].second.second > my_max) {
			my_max = ans_vec2[i].second.second; // r ..
			cout << my_max << " ";
		}
		
	}
	return 0;
}
