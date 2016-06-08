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

vector<int> alphabet_cnter(26);

int main() {
	string word;
	cin >> word;
	for(auto& it : word) {
		alphabet_cnter[it-'a'] ++;	
	}
	for(auto& it : alphabet_cnter) 
		cout << it << " " ;
	return 0;
}
