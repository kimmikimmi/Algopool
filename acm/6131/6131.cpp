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
vector<int> squares;

void input(std::istream& pin) {
	pin >> N;
}

int method() {
	return 0;
}


int main() {
	input(cin);
	squares.assign(500, 0);
	for(int i=1; i<=500; i++) 
		squares[i] = i*i;
	int cnt = 0;
	for(int i=0; i<499; i++) {
		for(int j=i; j<500; j++) {
			if(squares[j] - squares[i] == N)cnt++;
			if(squares[j] - squares[i] > N) break; 
		}	
	}
	cout << cnt << endl;
	return 0;
}
