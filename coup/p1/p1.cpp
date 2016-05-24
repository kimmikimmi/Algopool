#include <iostream>
#include <vector>
#include <algorithm>
I-string
using namespace std;

#define MAX 100
map<char, int> fridge; // 입력받은 문자열에서 각각의 케릭터가 몇개씩 들어있는지 저장하고 있는 자료구조입니다.
vector<pair<char, int>> v;


void method() {
}


void set_map_count(string str) { 
	int i=0;
	for(auto& p : str) {
		fridge[p]++;
	}
}

int main() {
	string str_fringe[MAX];
	
	for(int i=0; i<MAX; i++) 
		cin >> str_fringe[i];

	
	
	for(int i=0; i<MAX; i++) {
		std::transform(str_fringe[i].begin(), str_fringe[i].end(), str_fringe[i].begin(), tolower);
		if(str_fringe[i][str_fringe[i].size()-1] >= 'A' || str_fringe[i][str_fringe[i].size()-1] <= 'z') {
			str_fringe[i].resize(str_fringe[i].size()-1);
		}
	}
	for(int i=0; i<MAX; i++) {
		std::transform(str_fringe[i].begin(), str_fringe[i].end(), str_fringe[i].begin(), tolower);
		if(str_fringe[i][str_fringe[i].size()-1] >= 'A' || str_fringe[i][str_fringe[i].size()-1] <= 'z') {
			str_fringe[i].resize(str_fringe[i].size()-1);
		}
	}

	for(int i=0; i<str_fringe.size(); i++) {
		int last = str_fringe[i].size()-1;
		str_tmp = 
		if(str_fringe[i][0] == str_fringe[i][last]) {
			fridge[]
		}
	}

	return 0;
}
