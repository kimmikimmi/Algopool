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

/*
 *KMP 알고리즘의 경우 
 * pi Array와 
 *
 * prefix, suffix 에 관한 지식이 필요하다.
 *
 */

string word;
string pattern;

void input(std::istream& pin) {
	pin >> word >> pattern;
}



// O(m) 구현.
// 가장 단순한 방법으로 구현할 경우 O(m^3)
vector<int> getPi(string p) {
	
	int m = p.size();
	int j =0;
	
	vector<int> pi(m, 0);

	string sub_str;
	for(int i=1; i<m; i++) {

		while(j>0 && p[i] != p[j]) 
			j = pi[j-1];

		if(p[i] == p[j]) 
			pi[i] = ++j;
	}

	return pi;
}

// return indexes matched string starts
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = s.size();
	int m = p.size();
	int j = 0;
	
	for(int i=0; i<n; i++) {
		
		while(j>0 && s[i] != p[j]) 
			j = pi[j-1];
	
		if(s[i] == p[j]) {
			if(j == m-1) {
				ans.push_back(i-m+1);
				j = pi[j];
			} else 
				j++;
		}
	}

	return ans;
}

int main() {

	vector<int> my_vec = getPi("ababababc");
	for(auto& it : my_vec) cout << it << endl;

	return 0;
}
