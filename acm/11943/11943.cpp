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
int A,B,C,D;
void input(std::istream& pin) {
	pin >> A  >> B;
	pin >> C >> D;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	int case1 = A + D;
	int case2 = C + B;
	int ans = case1 > case2 ? case2 : case1;
	cout << ans;
	return 0;
}
