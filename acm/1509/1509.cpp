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

vector<int> cache;
string input_str;

void input(std::istream& pin) {
	pin >> input_str;
}

int felindrom(int x, int y) {
	int cnt = 0;
	int flag = 0;
	for(int i=x, j=y-1; i<=j;) {
		if(input_str[i] == input_str[j]) {
		//cout << "i = " << i << "  j = " << j << endl; 
			if(cnt == 0 ) flag = i;
			cnt++;
			i++;
			j--;
		} else {
			if(cnt == 0) {
				i++;
			} else {
				cnt = 0;
				j = y-1;
				i = flag+1;
			}
		}

	}
	return cnt;
}

int felindrom2(int x, int y) {
	int cnt = 0;
	int flag = -1;
	for(int i=x, j=y-1; i<=j;) {
		if(input_str[i] == input_str[j]) {
		//cout << "i = " << i << "  j = " << j << endl; 
			if(j == y-1) 
				flag = i;
			//cnt = 0;
			i++;
			j--;
		} else {
			if(flag != -1) {
				i = flag+1;
				j = y-1;
			} else {
				i++;
			}
			flag = -1;
			cnt++;
		}

	}
	return cnt;
}

int method(int n) {
	if(n==1) return 1;
	if(n==0) return 0;

	if(cache[n] != 10000) return cache[n];

	for(int i=0; i<n-2; i++) {
		int fel = felindrom2(i, n);
		cout << fel << endl;
		if(cache[n] > fel + method(n-i-1)) {
			cache[n] = fel + method(n-i-1);
		}
	}
	return cache[n];
}

void init_sol_vec(int& len, vector<int>& target_vec) {
	target_vec.assign(len+1, 10000);
	target_vec[0] = 0;
}

int main() {
	input(cin);

	int len = input_str.length();
	init_sol_vec(len, cache);
	for(int i=0; i<len; i++) {
		cout  << "i = " << i << " "  << felindrom2(i, len) << endl;
	}
	cout << method(len) << endl;

	for(int i=0; i<len; i++) {
		cout << "cache[" << i << "] = " << cache[i] << endl;
	}
	return 0;
}
