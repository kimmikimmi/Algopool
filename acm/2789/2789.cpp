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

string method() {

	word.erase(remove(word.begin(), word.end(), 'C'), word.end());
	word.erase(remove(word.begin(), word.end(), 'A'), word.end());
	word.erase(remove(word.begin(), word.end(), 'M'), word.end());
	word.erase(remove(word.begin(), word.end(), 'B'), word.end());
	word.erase(remove(word.begin(), word.end(), 'R'), word.end());
	word.erase(remove(word.begin(), word.end(), 'I'), word.end());
	word.erase(remove(word.begin(), word.end(), 'D'), word.end());
	word.erase(remove(word.begin(), word.end(), 'G'), word.end());
	word.erase(remove(word.begin(), word.end(), 'E'), word.end());










	return word;
}




int main() {
	input(cin);
	cout << method() << endl;
	return 0;
}
