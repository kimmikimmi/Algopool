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
int k;
void input(std::istream& pin) {
	pin >> N >> k;
}
vector<int> divisors;
int method() {
	for(int i=1; i<=N; i++) 
		if(N % i == 0) divisors.push_back(N/i);
	
	sort(divisors.begin(), divisors.end());
	if(divisors.size() < K) return 0;
	return divisors[k-1];
}

int main() {
	input(cin);
	cout << method();
	return 0;
}
