#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

#define MAX_DIST 89*89 + 109*109
#define UPPER_BOUND 150

vector<pair<int,int>> squares; 
vector<pair<pair<int,int>, int>> db;

void input(istream& in) {
	int w = -1;
	int h = -1;

	for(;;) {
		in >> h >> w;
		if(w == 0) break;
		pair<int,int> p1(h,w);
		squares.push_back(p1);
	}

}


// not gonna be used .
bool myfunction (pair<pair<int,int>,int>& i, pair<pair<int,int>,int>& j) {
	if(i.second == j.second) return i.first.first < j.first.first;
	return (i.second < j.second);
}



void fill_db() {
	int dist;
	for(int h=1; h<UPPER_BOUND; h++) {
		for(int w=h+1; w<=UPPER_BOUND; w++) {

			dist = h*h + w*w;
			
			if(dist > MAX_DIST) break;

			pair<int,int> p1(h,w);
			pair<pair<int,int>, int> p(p1,dist);
			db.push_back(p);
		}
	}
	sort(db.begin(), db.end(), [](pair<pair<int,int>,int> i, pair<pair<int,int>,int> j) {
		if(i.second == j.second) return i.first.first < j.first.first;
		return (i.second < j.second);
	});
}

void find_solution() {
	
	for(int i=0; i<squares.size(); i++) {
		for(int j=0; j<db.size(); j++) {
			if(squares[i].first == db[j].first.first && 
				squares[i].second == db[j].first.second) {
				cout << db[j+1].first.first << " " << db[j+1].first.second << endl;
				break;
			}
		}
	}
}

int main() {
	input(cin);
	 // for(auto p : squares) cout << p.first << " " <<  p.second << endl;
	fill_db();

	for(auto& iter : db) 
		cout << iter.first.first <<", "<< iter.first.second << ","<<iter.second << endl;
	cout << " --------------------------------------------------" << endl;
	
	find_solution();


	return 0;
}
