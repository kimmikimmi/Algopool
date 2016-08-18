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

#define ENEMY_WIN ": Evil eradicates all trace of Good"
#define GOOD_WIN ": Good triumphs over Evil"
#define DRAW ": No victor on this battle field"

int T;

int g1,g2,g3,g4,g5,g6;
int s1,s2,s3,s4,s5,s6,s7;


void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> T;
	int gandalf_score = 0;
	int sauron_score = 0;
	for(int i=0; i<T; i++) {
		cin >> g1 >> g2 >> g3 >> g4 >> g5 >> g6;
		cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
		gandalf_score = g1*1 + g2*2 + g3*3 + g4*3 + g5*4 + g6*10;
		sauron_score = s1*1 + s2*2 + s3*2 + s4*2 + s5*3 + s6*5 + s7*10;
		if(gandalf_score > sauron_score) 
			cout << "Battle " << i+1 << GOOD_WIN << endl;
		else if(gandalf_score < sauron_score) 
			cout << "Battle " << i+1 << ENEMY_WIN << endl;
		else 
			cout << "Battle " << i+1 << DRAW << endl;
	}
	return 0;
}
