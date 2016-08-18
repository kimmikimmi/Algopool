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

int T;
vector<string> str_bag;

void input(std::istream& pin) {
	pin >> T;
	string tmp_str;
	for(int i=0; i<T; i++) {
		pin >> tmp_str;
		str_bag.push_back(tmp_str);
	}
}

// return # 
int method(string& num) {
	int cnt = 0;
	if(num == "6174") return 0; 
	while(true) {
		vector<char> num_vec;

		for(auto& it : num) 
			num_vec.push_back(it); 
	
		string max_num, min_num;
	
		sort(num_vec.begin(), num_vec.end());
		for(auto& it : num_vec) 	
			min_num += it;
	
		sort(num_vec.rbegin(), num_vec.rend());
		for(auto&it : num_vec)
			max_num += it;

		int diff = stoi(max_num) - stoi(min_num);
//		cout << "diff = " << diff << endl;	
		if(diff == 6174) return cnt+1;
		else { 
			cnt++;
			if (diff < 1000) {
				string zero = "0";
				num = "0" + to_string(diff);
			} else
				num = to_string(diff);
		}
	}
	return 0;
}

int main() {
	input(cin);
	for(int i=0; i<T; i++)
		cout << method(str_bag[i]) << endl;
	return 0;
}
