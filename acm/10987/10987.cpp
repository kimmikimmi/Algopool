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

void input(std::istream& pin) {
	pin >> word;
}


bool isVowl(char c) {
   if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}	
int method() {
	int cnt = 0;
	for(auto& it : word)  {
		if(isVowl(it)) cnt++; 
	}

	return cnt;
}

int main() {
	input(cin);
	cout << method();
	return 0;
}
