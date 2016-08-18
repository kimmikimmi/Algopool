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
#include <bitset>

using namespace std;

int k;

void input(std::istream& pin) {
	pin >> k;
}

int main() {
	input(cin);
	for(int i=1; i<=k; i++) printf("1");
	for(int i=1; i<k; i++) printf("0");
	return 0;
}
