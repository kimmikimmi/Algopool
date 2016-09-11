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

int M,N;
vector<bool> num_table; 

void input(std::istream& pin) {
	pin >> M >> N;
	num_table.assign(N+1, true);
}

void method() {
	//1. 짝수 처리
	for(int i=0; i<=N; i=i+2) {
		num_table[i] = false;
	}
	num_table[1] = false; // 1은 소수 아니고..
	num_table[2] = true; 
	for(int i=3; i<=N; i= i+2) {
		for(int j=2; j*i<=N; j++) {
			num_table[i * j] = false;
		}
	}

}

int main() {
	input(cin);
	method();
	int sum = 0;
	int mini = 0;
	for(int i=M; i<=N; i++) 
		if(num_table[i]) {
			mini = i;
			break;
		}
	for(int i=M; i<=N; i++) {
		if(num_table[i]) sum += i;
	}
	if(mini ==0) cout << -1 << endl;
	else
		cout << sum << endl <<mini << endl;
	return 0;
}
