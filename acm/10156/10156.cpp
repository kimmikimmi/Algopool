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

int K,N,M;
void input(std::istream& pin) {
	pin >> K >> N >> M;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	if(K*N >M) cout << K*N-M << endl;
	else 
		cout << 0 << endl;
	return 0;
}
