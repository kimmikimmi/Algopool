////
//////  LCString_DP.cpp
//
//////  LCS 
//		implemented by Dynamic programming 
//////
//		두 문자열이 주어졌을 때, 최장 공통 부분 문자열을 찾는 알고리즘이다. 생명과학 분야가 발전함에
//		따라 어떤 두 개의 염기 서열을 비교해야 하는 상황이 많아졌기 때문에 각종 알고리즘이 나온 분야 이기도			하다.
//
//		위 방법처럼 다이나믹 알고리즘으로 푸는 방법이 제일 잘 알려진 방법이다. 두 문자열을 이용해서 일정한
//		규칙의 테이블을 만든 후 그 테이블을 살펴 보면서 최장 공통 부분 문자열을 찾아 낼 수 있다. 
//		이 경우 테이블을 따라 계산하므로 시간 복잡도는 O(n^2)이다.
//		
//////  Created by 김현준 on 16/08/2016.
//////  Copyright © 2016 김현준. All rights reserved.
//////
////
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

string str1;
string str2;

vector<vector<int>> table;

void input(std::istream& pin) {
	pin >> str1 >> str2;
}



pair<int, string> getLCS(string& pattern, string& target, int len_p, int len_t) {
// Declare variable.
	pair<int, string> p_lcs;
	string LCS("");
	int length_lcs = 0;
	int end_cs;
// Initializing table.
	table.assign(len_p+1, vector<int>(len_t+1));
	for(int i=0; i<len_p; i++) 
		table[i][0] = 0;
	for(int i=0; i<len_t; i++)
		table[0][i] = 0;

/***************************************************/
	for(int i=1; i<len_p+1; i++) {
		for(int j=1; j<len_t+1; j++) {
			if(pattern[i-1] == target[j-1]) 
				table[i][j] = table[i-1][j-1] + 1;
			else 
				table[i][j] = 0;
			if(table[i][j] > length_lcs) {
				length_lcs = table[i][j];
				end_cs = i;
			}
		}
	}	
/***************************************************/
	cout << "#\t#\t";
	for(auto& it : target) cout << it << "\t";
	cout << endl;
	for(int i=0; i<len_p+1; i++) {
		if(i==0) cout << "#\t";
		else 
			cout << pattern[i-1] << "\t";
		for(int j=0; j<len_t+1; j++) {
			cout << table[i][j] << "\t";

		}
		cout << endl;
	}	
	
/***************************************************/
	for(int i=0; i<length_lcs; i++) 
			LCS += pattern[end_cs-length_lcs+i];		

	p_lcs = make_pair(length_lcs, LCS);
	return p_lcs;
}

int main() {
	input(cin);
	int len1 = str1.length(); 
	int len2 = str2.length();
	cout << getLCS(str1, str2, len1, len2).first << endl << getLCS(str1, str2, len1, len2).second << endl;
	return 0;
}
