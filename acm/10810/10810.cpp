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

int N, M;
vector<int> baskets;

void input(std::istream& pin) {

}

int method() {
	return 0;
}
void myfunction() {

}
int main() {
	int a,b,c;
	cin >> N >> M;
	baskets.assign(N,0);
	
	for(int i=0; i<M; i++) {
		cin >> a >> b >> c;
		for(int i=0; i<b-a+1; i++) {
			baskets[a+i-1] = c;
		}
	}

	for(auto& it : baskets) cout << it << " " ;
	return 0;
}
