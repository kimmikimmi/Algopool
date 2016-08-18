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

int N,M;
vector<int> packages;
vector<int> each;
void input(std::istream& pin) {
	pin >> N >> M;
	packages.assign(M, 0);
	each.assign(M,0);
	for(int i=0; i<M; i++) {
		pin >> packages[i] >> each[i];
	}

}

int method() {

	return 0;
}

int main() {
	input(cin);
	int min_cost = 0;
	sort(packages.begin(), packages.end());
	sort(each.begin(), each.end());
	
	int cheap_line = each[0];
	int cheap_package = packages[0];
	// 1. 터진 기타줄이 6개 이하인 경우에.
	// 낱개로 사는게 더 싸는 경우에 낱개로만 사자.
	if(N < 6) { 
		if(cheap_package > cheap_line*N) min_cost = cheap_line * N;
		else 
			min_cost = cheap_package;
	} else { 
		if(cheap_package > cheap_line * 6) 
			min_cost = cheap_line * N;
		else 
			min_cost = min(cheap_package*(N/6 ) + cheap_line*(N%6), cheap_package*(N/6 + 1));
	}
	cout << min_cost << endl;	
	return 0;
}
