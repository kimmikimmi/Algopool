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
int t;
void input(std::istream& pin) {
	pin >> t;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	string word1, word2;
	for(int i=0; i<t; i++) {
		cin >> word1 >> word2;
		string p_word1 = word1;
		string p_word2 = word2;
		sort(word1.begin(), word1.end());
		sort(word2.begin(), word2.end());
		cout << p_word1 << " & " << p_word2 << " are ";
	   if(word1 == word2)
			cout << "anagrams." << endl;
		else 
			cout << "NOT anagrams." << endl;		

	}
	return 0;
}
