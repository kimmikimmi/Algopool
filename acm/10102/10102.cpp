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

int v;
string vote_res;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> v;
	cin >> vote_res;
	int a =0;
	int b =0;

	for(auto& it : vote_res) {
		if(it == 'A') a++;
		else
			b++;
	}
	if(a > b) 
		cout << "A" << endl;
	else if(a < b)
		cout << "B" << endl;
	else 
		cout << "Tie" << endl;

	return 0;
}
