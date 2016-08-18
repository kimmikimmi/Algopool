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

string plain_text;
string key;

void input(std::istream& pin) {
	getline(pin,plain_text);
	pin	>> key;
}

string vigenere_encrypt(string p, string k) {
	
	string enc_msg(p);
	int p_len = p.size();
	int k_len = k.size();

	for(int i=0; i<p_len; i++) {
		if(p[i] == ' ') {
			enc_msg[i] = ' ';
			continue;
		}	

		int each_digit = p[i] - key[i%k_len];
//		cout << each_digit << endl;
		if(each_digit <= 0) each_digit = 1 + 'z' - ('a' - each_digit);
		enc_msg[i] = (char)(each_digit + 'a' -1);
	}

	return enc_msg;
}

int main() {
	input(cin);
	cout << vigenere_encrypt(plain_text, key);
	return 0;
}
