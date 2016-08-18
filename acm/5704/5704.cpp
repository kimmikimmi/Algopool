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

int method() {
	return 0;
}

int main() {
	string str_buf = "";
	while(true) {
		getline(cin, str_buf);
		//cout << str_buf << endl;
		if(str_buf[0] == '*') break;
		bool bit_map[26] = {false};
		for(auto& it : str_buf) {
			if(it >= 'a' && it <= 'z') {
				bit_map[it-'a'] = true;
			}
		}
		int cnt = 0;
		for(auto& it : bit_map) 
		{
			//cout << it << " ";
			if(it) cnt++;   
		}
		if(cnt == 26) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}
