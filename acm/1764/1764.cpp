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

map<string, bool> name_map;
int N,M;

vector<string> names;
int cnt;
void input(std::istream& pin) {
	pin >> N >> M;
	string tmp_str;
	for(int i=0; i<N; i++) {
		pin >> tmp_str;
		name_map[tmp_str] = true;
	}
	for(int i=0; i<M; i++) {
		pin >> tmp_str;
		if(name_map[tmp_str]) {
			names.push_back(tmp_str);
			cnt++;
		}
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	sort(names.begin(), names.end());
	cout << cnt  << endl;
	for(auto& it : names) printf("%s\n", it.c_str());

	return 0;
}
