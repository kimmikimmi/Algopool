////
//////  LCString_Suffix Array + LCP Array.cpp
//////  LCString_SA_LCP
//		LCP = Longest Common prefix
//		다이나믹 알고리즘의 시간복잡도는 O(n^2)는 실제 자연에서 볼 수 있는 염기 서열의 길이를 생각해보면
//		매우 오래 걸릴 뿐더러, 메모리 낭비 역시 심하다. 수많은 컴퓨터 과학자들과 수학자들이 이 문제에 대해 
//		매달려 왔으며 이에 대한 해결법 중 하나가 Suffix Array(Suffix Tree를 대체하기 위해 만들어진 배열)를 
//		활용하는 방법이었다.
//		비교하고자 하는 두 문자열을 합한 뒤 그 문자열의 Suffix Array를 구헀다면 LCP Array를 O(n)만에 구할			수 있다. 이 때의 LCP Array를 이용하여 최대 공통 부분 문자열을 찾아 낼 수 있다. 이 때의 탐색과 
//		LCP Array를 만드는 데 걸리는 시간 복잡도는 O(n)이므로 Suffix Array를 구하는 시간 복잡도에 따라서 
//		성능이 좌우된다. 
//////
//////  Created by 김현준 on 29/06/2016.
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

#include "sa_lcp_linear.h"

using namespace std;

string str1, str2;

//접미사 배열은 접미사를 사전순으로 저장하여 각 접미사의 시작 인덱스를 저장하고 있다.
vector<int> suffix_arr;

vector<int> lcp_array;

int len;
void input(std::istream& pin) {
	pin >> len;
	pin >> str1;
	//pin >> str1 >> str2;
}

struct SuffixComparator {
	const string& s;
	SuffixComparator(const string& s) : s(s) {}

	bool operator()(int i, int j) {
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
	}
};

void make_suffix_array(string& target, int len) {
	suffix_arr.assign(len, 0);

	for(int i=0; i<len; i++) suffix_arr[i] = i;
	
	sort(suffix_arr.begin(), suffix_arr.end(), SuffixComparator(target));
}

// 한번 이상 반복되는 부분 문자열중 가장 긴놈의 길이 찾기.
int method(string& target, int len) {
	int sol = 0;
	int cnt = 0;
	int s = 0;
	
	lcp_array.assign(len, -1);

	for(int i=0; i<len-1; i++) {
		s = suffix_arr[i] > suffix_arr[i+1] ? (len-suffix_arr[i]) : (len - suffix_arr[i+1]);
	    cnt = 0;
		for(int j=0; j<s; j++) {
			if(target[suffix_arr[i]+j] != target[suffix_arr[i+1] + j]) 
				break;
			cnt++;
		}
		lcp_array[i+1] = cnt;
		//cout << "cnt = " << cnt << endl;
		if(cnt > sol) sol = cnt;	
	}
	return sol;
}

struct Comparator{
    const vector<int>& group;
    int t;

    Comparator(const vector<int>&_group, int _t):group(_group),t(_t){}
    bool operator()(int a, int b){
        if(group[a]!=group[b]) return group[a]<group[b];
        return group[a+t]<group[b+t];
    }
};



// 내꺼 아님 !
vector<int> getSuffixArray(const string&s){
    int n=s.size();
    int t=1;
    vector<int>group(n+1);
    for(int i=0; i<n; ++i) group[i]=s[i];
    group[n]=-1;
    vector<int>perm(n);
    for(int i=0; i<n; ++i) perm[i]=i;
    while(t<n){
        Comparator compareUsing2T(group,t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t*=2;
        if(t>=n) break;
        vector<int>newGroup(n+1);
        newGroup[n]=-1;
        newGroup[perm[0]]=0;
        for(int i=1; i<n; ++i)
            if(compareUsing2T(perm[i-1],perm[i]))
                newGroup[perm[i]]=newGroup[perm[i-1]]+1;
            else
                newGroup[perm[i]]=newGroup[perm[i-1]];
        group=newGroup;
    }
    return perm;
}
//내꺼 아님
vector<int> getLCP(const vector<int>& pos, const string&s){
    int n=pos.size();
    vector<int>rank(n), height(n);
    for(int i=0; i<n; ++i)
        rank[pos[i]]=i;

    for(int i=0, h=0; i<n; ++i){
        if(rank[i]>0){
            int j=pos[rank[i]-1];
            while(i+h <n && j+h<n && s[i+h] ==  s[j+h])
                h++;
            height[rank[i]]=h;
            if(h>0) h--;
        }
    }
    return height;
} 

int main() {
	input(cin);
	len = str1.size();
	//suffix_arr = getSuffixArray(str1);
	make_suffix_array(str1, len);
	//for(auto& it : suffix_arr) cout <<it << endl;
	//method(str1, len);
	lcp_array = getLCP(suffix_arr, str1);
	int max_val = 0;
	for(auto& it : lcp_array) {
		if(max_val < it) max_val = it ;
	}
	cout << max_val;
	// for(auto& it : suffix_arr) 
	// 	cout << it+1 << " ";
	// cout << endl;
	// int i=0;
	// for(auto& it : lcp_array) {
	// 	if(i== 0) cout << 'x' << " ";
	// 	else cout << it << " ";
	// 	i++;
	// }
	return 0;
}



