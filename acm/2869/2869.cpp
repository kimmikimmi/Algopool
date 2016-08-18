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

long long A,B,V;

void input(std::istream& pin) {
	pin >> A >> B >> V;
}

long long method() {
	long long cnt = 0;
	for(int i=0; ;i++) { 
		if( (A + (A-B)*i) >=  V) {
			cnt = i+1;
			break;
		} 
	}
	
	return cnt;
}

long long method2() {
	long long ans = 0;
	if(B-A == 0) return 0;
	ans = (V-A) / (A-B);
	if( (V-A)%(A-B) != 0) ans++; 
	
	return ans + 1;
}

int main() {
	input(cin);
	cout << method2();
	return 0;
}
