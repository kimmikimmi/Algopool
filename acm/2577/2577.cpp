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
	int ans = a* b * c;
	string my_str = to_string(ans);
	vector<int> my_map(10,0);
	for(auto& it : my_str) {
		my_map[it-'0']++;
	}
	for(auto& it : my_map) cout << it << endl;
	return 0;
}
