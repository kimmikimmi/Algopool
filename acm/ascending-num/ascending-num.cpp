#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
문제
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이 때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

입력
첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

출력
첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.
*/
int num;
int cache[11][1001];
#define mod  10007

void init_cache() {
	for(int i=0; i<11; i++) 
		for(int j=0; j<1001; j++) cache[i][j] = -1;
}

void input(istream& minki) {
	minki >> num;
	// cout << num << endl;
}

int method(int n, int r) {
	if(cache[n][r] != -1) return cache[n][r];
	
	int v = n + r -1;

	//if(v < r || n == 0) return 0;
	if(v == r) return cache[n][r] = 1;
	if(r == 0 ) return cache[n][r] = 1;	
	if(r == 1) return cache[n][r] = v;

	return cache[n][r] = method(n-1, r)%mod + method(n, r-1)%mod;
}

int main() {
	input(cin);
	init_cache();
	cout << method(10,num)%mod << endl;

	return 0;
}
