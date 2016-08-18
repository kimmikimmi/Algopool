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
	int t; // # of testcases
	int n; // # of phone numbers
	cin >> t;
	vector<string> str_bag;
	for(int i=0; i<t; i++) {
		cin >> n;

		string tmp;
		str_bag.clear();
		str_bag.resize(n);
		for(int j=0; j<n; j++) {
			cin >> tmp;
			str_bag[j] = tmp;
//			cout << i << " " << j << " " << temp << endl;
		}

		sort(str_bag.begin(), str_bag.end());
//		for(auto& it : str_bag) cout << it << endl;
		bool flag = true;	
		for(int j=0; j<n-1; j++) {
			int size_j = str_bag[j].size(); 
			int size_next_j = str_bag[j+1].size();
			if(size_j > size_next_j) continue;
			if(str_bag[j+1].compare(0, size_j, str_bag[j]) == 0) {
				cout << "NO"  << endl;
				flag = false;
				break;
			}
		}
		if(flag)  
			 cout << "YES" << endl;
			
	}
	return 0;
}
