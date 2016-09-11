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

int N,S;
vector<int> u;
void input(std::istream& pin) {
	pin >> N >> S;
	int tmp;
	for(int i=0; i<N; i++) {
		pin >> tmp;
		u.emplace_back(tmp);
	}
}
int ans;

void subset(int k, int sum) {
	if(k >= N) return;
	if(sum + u[k] == S) ans++;
	
	subset(k+1, sum + u[k]);
	subset(k+1, sum);				
}

int main() {
	input(cin);
	//sort(u.begin(), u.end());
	subset(0,0);
	cout << ans << endl;
	return 0;
}
