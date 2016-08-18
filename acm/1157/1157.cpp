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
string word;
vector<pair<char,int>> bit_map;

void input(std::istream& pin) {
	pin >> word;
	pair<char, int> p;
	bit_map.assign(26, p);
	std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	for(auto& it : word) {
		bit_map[it-'A'].first = it;
	    bit_map[it-'A'].second += 1;	
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	sort(bit_map.begin(), bit_map.end(), [](pair<char,int> p1, pair<char, int> p2) {
		return p1.second > p2.second;
			});
	if(bit_map[0].second == bit_map[1].second) cout << "?" << endl;
	else
		cout << bit_map[0].first << endl;
	return 0;
}
