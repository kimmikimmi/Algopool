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

int method2() {
	int cnt = 0;
	vector<bool> bit_map(34, false);
	for(int i=word.size()-1; i>=0; ) {
		if(i >0) {
			if(word[i] == '=') {
				if(i-2 >=0 && word[i-2] == 'd' && word[i-1] == 'z') {
					cnt++;
					bit_map[26] = true;
					i = i-3;
				}
				else if(word[i-1] == 'c' || word[i-1] == 's' || word[i-1] == 'z') {
					cnt++;
					if(word[i-1] == 'c') 	bit_map[27] = true; 
					else if(word[i-1] == 's') bit_map[28] = true;
					else if(word[i-1] == 'z') bit_map[29] = true;
					i = i-2;
				} else 
					i--;
			} else if(word[i] == '-') {
					if(word[i-1] == 'c' || word[i-1] == 'd') {
						cnt++;
						if(word[i-1] == 'c') bit_map[30] = true;
						else if(word[i-2] == 'd') bit_map[31] = true;
						i = i-2;
					} else 
						i--;
			} else if(word[i] == 'j') {
					if(word[i-1] == 'l' || word[i-1] == 'n') {
						cnt++;
						if(word[i-1] == 'l') bit_map[32] = true;
						else if(word[i-1] == 'n') bit_map[33] = true;
						i = i-2;
					} else {
					    cnt++;	
						bit_map['j' - 'a'] = true;
						i--;
					}	
			} else {
				cnt++;
				bit_map[word[i] -'a'] = true;
				i--;
			}
		}
		else { 
			cnt++;
			bit_map[word[i] -'a'] = true;
			i--;
		}
	}

	int cnt2 = 0;
	//for(auto i=0; i<34; i++) {
	//	if(bit_map[i]) cnt2++;
	//	cout << (char)(i+'a') << "\t" <<  bit_map[i] << endl;
	//}
	//cout << cnt2 << endl;
	
	return cnt;
}


int main() {
	input(cin);
	 cout << method2();
	return 0;
}
