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
int N, M;


void input(std::istream& pin) {
	pin >> N >> M;
}

int method() {
	int smaller = 0;
	if(M > N) 
		return N-1 + N * (M-1);	
	else 
		return M-1 + M * (N-1);
}

int main() {
	input(cin);
	cout << method();
	return 0;
}
