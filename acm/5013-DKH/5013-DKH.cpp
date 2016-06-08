#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int N;
vector<string> battles;

void input(istream& in) {
	in >> N;
	string tmp;
	for(int i=0; i<N; i++) {
		in >> tmp;
		battles.push_back(tmp);
	}
}

bool isWon(string battle) {
	string lost = "DC";
	std::size_t found = battle.find(lost);
	if(found == string::npos) return true;
	return false;
}

int main() {
	input(cin);
	int cnt = 0;
	for(auto& it : battles) {
		if(isWon(it)) cnt ++;
	}
	cout << cnt << endl;

	return 0;
}
