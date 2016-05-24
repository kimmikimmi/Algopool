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
int N;
int K;
long long int cache[500][201];
#define mod  1000000000

void init_cache() {
	for(int i=0; i<500; i++) 
		for(int j=0; j<201; j++) cache[i][j] = -1;
}

void input(istream& minki) {
	minki >> N >> K;
	// cout << num << endl;
}

long long int combination(int n, int r) {

	if(cache[n][r] != -1) return cache[n][r];
	
	if(r == 0 || n == r) {
		cache[n][r] = 1; 
		return 1;
	}
	cache[n][r] = combination(n-1, r)%mod + combination(n-1,r-1)%mod;

	return cache[n][r];
}

int main() {
	input(cin);
	init_cache();
	cout << combination(N+K-1,K-1)%mod << endl;

	return 0;
}
