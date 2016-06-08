#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int R,C;
vector<pair<int, int>> boats;

void input(istream& in) {
	in >> R >> C;
	char cursor;
	bool visited;
	for(int i=0; i<R; i++) {
		visited = false;
		for(int j=0; j<C; j++) {
			in >> cursor;
			if(!visited && cursor >= '0' && cursor <= '9' ) {
				pair<int, int> p(i, j);
				boats.push_back(p);
				visited = true;	
			}
		}
	}
}

void method() {
	sort(boats.begin(), boats.end(), [](pair<int, int> p1, pair<int,int> p2) 
			{ return p1.second>p2.second; });
	
	vector<pair<int, int>> rank; // <line#, rank>
	int cnt = 1;
	
	pair<int, int> p(boats[0].first, cnt);
	rank.push_back(p);

	for(int i=1; i<boats.size(); i++) {
			
		if(boats[i].second != boats[i-1].second)  // two boats's ranks are same..
			cnt++;		
		pair<int, int> p(boats[i].first, cnt); 
		rank.push_back(p);
	}
	sort(rank.begin(), rank.end(), [](pair<int,int> p1, pair<int, int> p2 ){ return p1.first<p2.first;});
	for(auto& it : rank) cout  << it.second << endl;
	
}

int main() {
	input(cin);
	method();
	return 0;
}
