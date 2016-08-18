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

int N;
int lastname[26];
void input(std::istream& pin) {
	pin >> N;
	string tmp;
	for(int i=0; i<N; i++) {
		pin >> tmp;
		lastname[tmp[0]-'a']++;
	}
}

int method() {
	return 0;
}

int main() {
	input(cin);
	vector<char> print_char;
	for(int i=0; i<26; i++) { 
		if(lastname[i] >=5) 
			print_char.push_back( (char)('a'+i));
	}
	if(print_char.empty()) cout << "PREDAJA";
	else
		for(auto& it : print_char) cout << it ;
	return 0;
}
