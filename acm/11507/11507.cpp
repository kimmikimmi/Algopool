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

string S;


struct card {
	char shape;
	string n;
	int r_n;
	card() : shape(0), n("") {}
};

vector<card> cardset;

void input(std::istream& pin) {
	pin >> S;
	int s_len = S.size();
	card c;
	for(int i=0; i<s_len; i++) {
		if(i%3 == 0) {
			c.shape = S[i];
			c.n.clear();
		}else	
			c.n += S[i];

		if(i%3 == 2) cardset.push_back(c);
	}
}

int method() {
	int chker[4][13];
	int p = 13;
	int k = 13;
	int h = 13;
	int t = 13;

	for(int i=0; i<4; i++) 
		for(int j=0; j<13; j++)
			chker[i][j] = 0;
	bool greska = false;
	for(int i=0; i<cardset.size(); i++) {

		int first_digit = (cardset[i].n[0] - '0') * 10;
		int second_digit = (cardset[i].n[1] - '0') -1;
		switch(cardset[i].shape) {
			case 'P' :
				chker[0][first_digit + second_digit] ++;
				p--;
				break;
			case 'K' :
				chker[1][first_digit + second_digit]++;
				k--;
				break;
			case 'H' :
				chker[2][first_digit + second_digit]++;
				h--;
				break;
			case 'T' :
				chker[3][first_digit + second_digit]++;
				t--;
				break;
		}
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<13; j++) {
			if(chker[i][j] >= 2) {
				greska = true;
				break;
			}
		}
	}

	if(greska) cout << "GRESKA" << endl;
	else
		cout << p << " " << k << " " << h << " " << t << endl;
	
	return 0;
}

int main() {
	input(cin);
	method();
	return 0;
}
