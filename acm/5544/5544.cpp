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

struct team {
	int name;
	int score;
};
vector<team> scores;
int N;
void input(std::istream& pin) {
	pin >> N;
	team t;
	scores.assign(N, t);
	int a,a_score,b,b_score;
	int size = N*(N-1)/2;
	for(int i=0; i<size; i++) {
		pin >> a >> b >> a_score >> b_score;
		scores[a-1].name = a;
		scores[b-1].name = b;
		if(a_score == b_score) {
			scores[a-1].score += 1;
			scores[b-1].score += 1;
		} else if(a_score > b_score) {
			scores[a-1].score += 3; 
		} else {
			scores[b-1].score += 3;
		}
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	sort(scores.begin(), scores.end(), [](team a, team b){return a.score>b.score;});
	//for(auto& it : scores) cout << it.name <<" " <<  it.score << endl;

	int ranking[N+1];
	int current_rank = 1;	
	int carry = 0;
	ranking[scores[0].name] = current_rank; 
	for(int i=1; i<scores.size(); i++) {
		if(scores[i].score == scores[i-1].score) {
			ranking[scores[i].name] = current_rank;
			carry++;
		}
		else {
			current_rank += carry;
			carry = 0;
			current_rank++;
			ranking[scores[i].name] = current_rank;
		}
	}
	for(int i=1; i<N+1; i++) 
		cout <<  ranking[i]<< endl;
	return 0;
}
