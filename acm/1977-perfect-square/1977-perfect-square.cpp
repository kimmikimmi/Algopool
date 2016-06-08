#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int N;
int M;
void input(istream& in) {
	in >> N >> M;
}

void method() {
	int sqrt_N = (int)sqrt(N);
	int sqrt_M = (int)sqrt(M);
	int begin_N, end_M;
	int min_square = sqrt_N*sqrt_N == N ? sqrt_N : (sqrt_N+1);
	int max_square = sqrt_M*sqrt_M == M ? sqrt_M : (sqrt_M-1);
	int sub_sum = 0;
	if(min_square*min_square >= M) {
		cout << -1 << endl;
		return;
	}
	for(int i=min_square; ; i++) {
		if(i*i > M) break;
		sub_sum += i*i;
	}
	cout << sub_sum << endl;
	cout << min_square*min_square << endl;
		
}

int main() {
	input(cin);
	method();
	return 0;
}
