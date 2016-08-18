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
#include <queue>
using namespace std;

#define graph vector<vector<int>>



int N; // 사람수 
graph adj_list;

void input(std::istream& pin) {
	pin >> N;
	char isFriend;
	
	adj_list.resize(N);

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			pin >> isFriend;
			if(isFriend == 'Y') 
				adj_list[i].push_back(j);
		}
	}	

}

int method(int who) {
	queue<int> q;
	int cnt = 0;
	vector<bool> bit_map(N, 0);
	

	bit_map[who] = true;
	for(auto it=adj_list[who].begin(); it!=adj_list[who].end(); it++) {
			cnt++;
			q.push(*it);
			bit_map[*it] = true;
//			cout << "first loop : who =  " << who << "is friend of = " << *it << endl;
	}

	int current ;
	while(!q.empty() ) {
		current = q.front();
		q.pop();
		for(auto it=adj_list[current].begin(); it!=adj_list[current].end(); it++) {
			if(!bit_map[*it]) {
				cnt++;	
				bit_map[*it] = true;
//				cout << "who =  " << who << "is friend of = " << *it << endl;
			}
		}
	}

	return cnt;
}

int main() {
	input(cin);
	int doctor_who = 0;
	int candidate;
	for(int i=0; i<N; i++) {
		candidate = method(i);
//		cout << "candidate = " << candidate << endl;
		if(candidate > doctor_who) 
			doctor_who = candidate;
	}
	cout << doctor_who;

	return 0;
}
