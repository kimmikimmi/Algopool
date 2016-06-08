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

bool method() {
	int len = word.size(); 
	for(int i=0; i<len/2; i++) 
		if(word[i] != word[len-1-i]) return false;
	
	return true;
}

int main() {
	input(cin);
	if(method()) cout << 1 <<endl;
	else 
		cout << 0 << endl;
	return 0;
}
