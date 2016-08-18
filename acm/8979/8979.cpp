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

int N; // 국가의 수
int K; // 출력해야 하는 국가의 번호 !

struct Contry {
	int num;
	int gold;
	int silver;
	int bronze;
	int o_rank;
};

vector<Contry> contries;

void input(std::istream& pin) {
	pin >> N >> K;
	for(int i=0; i<N; i++) {
		Contry con_buf;
		pin >> con_buf.num >> con_buf.gold >> con_buf.silver >> con_buf.bronze;
		contries.push_back(con_buf);
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	sort(contries.begin(), contries.end(), [](Contry c1, Contry c2) {
			if(c1.gold == c2.gold) {
				if(c1.silver == c2.silver) 
					return c1.bronze > c2.bronze;
				return c1.silver > c2.silver;
			}
			return c1.gold > c2.gold;
			});
	int _rank = 1;
	contries[0].o_rank = 1;
	for(int i=1; i<N; i++) {
			if(contries[i].gold == contries[i-1].gold && 
					contries[i].silver == contries[i-1].silver &&
						contries[i].bronze == contries[i-1].bronze) {
				contries[i].o_rank = _rank;
			} else 
				contries[i].o_rank = ++_rank;
	
	}
	for(auto& it : contries) {
		if(it.num == K) 
			cout << it.o_rank;
	}
	return 0;
}
