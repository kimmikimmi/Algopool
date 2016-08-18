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
#define u_int unsigned int
int T;
vector<long long> makers;

void input(std::istream& pin) {
	pin >> T;
	makers.assign(T, 0);
	for(int i=0; i<T; i++)
	   pin >> makers[i];	
}

string get_right_number(string target) {
	string dest = target;
	if(target[0] > '4') {
		dest[0] = '5';
		for(int i=1; i<target.size(); i++) {
			dest[i] = '0';
		}
	} else {
		dest = target;
	}
	return dest;
}

string get_opposite(string target) {
	
	string opposite = target;

	for(int i=0; i<opposite.size(); i++) 
		opposite[i] = (char)('9' - (opposite[i]-'0'));
	
	return opposite;
}

long long  get_loveliness(int num) {
	string oneside = to_string(num);
	oneside = get_right_number(oneside);
	string opposite = get_opposite(oneside);


	//cout << oneside << " " << opposite << endl;
	long long answer = stoll(oneside);
	answer *= stoll(opposite);
	return answer;//answer;
}

int main() {
	input(cin);
	for(auto it : makers) {
		cout << get_loveliness(it) << endl;	
	}

	return 0;
}
