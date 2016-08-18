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

vector<bool> bitmap;
int main() {
	int a;
	//vector<int> int_bag;
	while(true) {
		int cnt = 0;
		string word;
		//scanf("%d", &a);
		cin >> word;
		if(word == "0") return 0;
		a = stoi(word);

		bool bitmap[10000] = {false};	
		bitmap[a] = true;
		while(true) {
			string a_str = to_string(a*a);
			int a_str_len = a_str.size();

			if(a_str_len != 8) {
				for(int i=0; i<8-a_str_len; i++) 
					a_str = "0" + a_str;
			}
		
			a = stoi(a_str.substr(2,4));
		
			if(bitmap[a]) break;
		
			bitmap[a] = true;
			
			cnt++;
		}
		printf( "%d\n", cnt + 1);
	}

	return 0;
}
