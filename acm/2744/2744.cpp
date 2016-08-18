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
// A : 65 a = 97
void input(std::istream& pin) {
	pin >> word;
}

int method() {
	for(int i=0; i<word.size(); i++) {
		if(word[i] >= 'a') word[i] -= 32;
		else
			word[i] += 32;	
	}
	return 0;
}

int main() {
	input(cin);
		method();
	cout << word << endl;
	return 0;
}
