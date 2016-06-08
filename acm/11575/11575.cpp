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

void input(std::istream& pin) {

}

string encrypt(int a, int b, string str) {
	int str_len = str.size();
	string encrypted_text = "";
	for(int i=0; i<str_len; i++)
		encrypted_text += (a*(str[i]-'A')+b)%26 + 'A';
	return encrypted_text;
}

int main() {
	int T;
	int a,b;
	string plainText;
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> a >> b;
		cin >> plainText;
		cout << encrypt(a,b,plainText) << endl;
	}	
	return 0;
}
