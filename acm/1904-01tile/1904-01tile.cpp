#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

/*
0000
0011
1100
1001
1111

XXXXX
5/2 + 1 = 3

C(3,0) + C(3,1) + C(3,2) 

길이가 홀수인 경우
N/2 = K

C(K+1, 0) + C(K+1, 1) + .... + C(K+1, K)

길이가 짝수인 경우
N/2 = K
C(K,0) + C(K,1) + C(K,2) + ... + C(K,K).
1 + 2 + 2 
길이가 홀수인 경우 
조합 문제인가?

아니다. 점화적으로 표현 가능해?

ㅇㅇ
*/

using namespace std;

int N;
//std::vector<unsigned int> cache;

unsigned int cache[1000000];
void input(istream& in) {
	in >> N;
	// cache.resize(N+1);
	cache[0] = 0;
	cache[1] = 0;
	cache[2] = 2;
	cache[3] = 3;
	
}

unsigned int method(int i) {

	if (i < 4) return cache[i];
	if(cache[i] != 0) return cache[i];
	return cache[i] = method(i-1)%15746 + method(i-2)%15746;

}

int main() {
	input(cin);
	// cout << method(N);
	 
	
	if(N <2) cout << 0 << std::endl;
	else if(N == 2) cout << 2 << endl;
	else if(N == 3) cout << 3 << endl;

	else {
		int i=4;
		int j=2, k=3, sum;
		while(i < N+1)
	    {
			sum=(j+k) % 15746;
			j=k % 15746;
			k=sum % 15746;

			i++; 
		}
		cout << sum << endl;
	}
	
	return 0;
}
