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

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> bag(3);
	bag[0] = a;
	bag[1] = b;
	bag[2] = c;
	sort(bag.begin(), bag.end());
	for(auto& it : bag) cout << it << " ";
	return 0;
}
