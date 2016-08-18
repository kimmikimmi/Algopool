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

int n, m, q;
struct problem {
	bool ac;
	int taken_time;
	int wrong_cnt;
};

struct team {
	int num;
	int ac_cnt;
	int total_time;
	vector<problem> probs;
};

vector<team> teams;
void input(std::istream& pin) {
	
	pin >> n >> m >> q;
	
	team t;
	problem p;

	teams.assign(n, t);
	for(int i=0; i<n; i++) 
		teams[i].probs.assign(m, p);
		

	int a,b,c;
	string d;

	for(int i=0; i<q; i++) {
		pin >> a >> b >> c >> d;
	
		if(teams[b-1].probs[c-1].ac) continue;
		
		teams[b-1].num = b;
		
		if(d == "AC") { 
			teams[b-1].probs[c-1].ac = true;
			teams[b-1].ac_cnt++;
			teams[b-1].probs[c-1].taken_time = a;
		}
		else {
			teams[b-1].probs[c-1].ac = false;
			teams[b-1].probs[c-1].wrong_cnt++;
		}
	}
}

int main() {
	input(cin);
	for(int i=0; i<n; i++) {
		for(auto& it : teams[i].probs) {
			if(it.ac) 
				teams[i].total_time += it.taken_time + it.wrong_cnt*20;
		}
//		cout << "팀 번호 : " << teams[i].num << " 맞은 문제 수 : " << teams[i].ac_cnt <<  
//			"문제 푸는데 걸린 시간 : " << teams[i].total_time << endl;
	}
	sort(teams.begin(), teams.end(), [](team t1, team t2) {
			if(t1.ac_cnt == t2.ac_cnt) { 
				if(t1.total_time == t2.total_time) 
					return t1.num < t2.num;
				return t1.total_time < t2.total_time;
			} 
			return t1.ac_cnt > t2.ac_cnt;});
	for(auto& it : teams) {
		cout << it.num << " " << it.ac_cnt << " " << it.total_time << endl;
	}
	return 0;
}
