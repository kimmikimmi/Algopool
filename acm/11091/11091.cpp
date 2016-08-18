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
#include <cctype>

using namespace std;

int N;
vector<string> str_bag;

void input(std::istream& pin) {
	//pin >> N;

	string tmp_str;

	getline(pin, tmp_str);
	N = stoi(tmp_str);
	for(int i=0; i<N; i++) {
		getline(pin,tmp_str); 
		str_bag.push_back(tmp_str);
	}
}

int main() {
	input(cin);
	for(int i=0; i<str_bag.size(); i++) {
		string dest_str ;
		dest_str.resize(str_bag[i].size());
		transform(str_bag[i].begin(), str_bag[i].end(), dest_str.begin(), ::tolower);
		str_bag[i] = dest_str;
//		cout << "str_bag[" << i << "] = "<< str_bag[i] << endl; 
	
	}

	for(auto& word : str_bag) {
		vector<bool> bit_map(26,false);
//		cout << "word = " << word << endl;
		for(int i=0; i<word.size(); i++) {
			if(word[i] >= 'a' && word[i] <='z') 
				bit_map[word[i]-'a'] = true;
		}
		
		int pan_flag = true;
		
		for(auto it : bit_map) 
			if(!it) pan_flag = false;
		
		if(pan_flag) {
			cout << "pangram" << endl;

		} else {
			cout << "missing " ;
			for(int i=0; i<bit_map.size(); i++) 
				if(bit_map[i] == false) cout << (char)('a' + i);  
			cout << endl;	
		}
	}
		
	return 0;
}
