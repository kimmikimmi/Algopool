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

int L;
string word;
vector<string> suffix_array;

void input(std::istream& pin) {
	pin >> L;
	pin >> word;
	   	
}

vector<string> make_suffix_array(string& targ_str, vector<string>& s_arr, int len) {
	s_arr.assign(len, "");
	for(int i=0; i<len; i++) 
		s_arr[i] = targ_str.substr(i, len-i);

	return s_arr;
}

int method() {
	return 0;
}

int main() {
	input(cin);
	int word_size = word.size();
	make_suffix_array(word, suffix_array, word_size);
	sort(suffix_array.begin(), suffix_array.end());
	string max_str;
	int maxx_size;
	for(int i=0; i< word_size-1; i++) {
		int shorter_len = suffix_array[i].size() > suffix_array[i+1].size() ?
				suffix_array[i+1].size() : suffix_array[i].size();

		int tmp_size = 0;
		for(int j=0; j<shorter_len; j++) {
			if(suffix_array[i][j] != suffix_array[i+1][j]) break;
			tmp_size++;
		}

		if(tmp_size > maxx_size) 
			maxx_size = tmp_size;
	}
	cout << maxx_size  << endl;
	return 0;
}
