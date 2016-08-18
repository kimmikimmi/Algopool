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
int N;
vector<int> hansu_seq(1001,0);

void init_hansuVec() {
	for(int i=0; i<100; i++) 
		hansu_seq[i] = i;
}

void input(std::istream& pin) {
	pin >> N;
}

int getHansu(int n) {
	if(hansu_seq[n] != 0) return hansu_seq[n];
	
	string n_str = to_string(n);
	int nth = 1;
	int len = n_str.size();
	int dif = n_str[1] - n_str[0];
	for(int i=1; i<len; i++) {
		if(n_str[i] - n_str[i-1] != dif) {
			nth = 0;
			break;
		}	
	}

	hansu_seq[n] = nth + hansu_seq[n-1]; 
	return hansu_seq[n];
}

int main() {
	input(cin);
	init_hansuVec();
	for(int i=0; i<=N; i++) 
		getHansu(i);
	cout << hansu_seq[N] << endl;
	return 0;
}
