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
vector<string> names;
void input(std::istream& pin) {
	string _str;
	for(int i=0; i<5; i++) {
		pin >> _str;
		names.push_back(_str);
	}	
}

bool is_FBI(string _str) {
	if(_str.find("FBI") != -1)  	
		return true;

	return false;
}

int main() {
	input(cin);
	int cnt = 0;
	for(int i=0; i<names.size(); i++) {
		if(is_FBI(names[i])) {
			cout << i+1 << " "; 
			cnt ++;
		}
	}	
	if (cnt == 0) cout << "HE GOT AWAY!" << endl;


	return 0;
}
