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

int N;
vector<int> bag;
vector<int> bag2;
void input(std::istream& pin) {
	pin >> N;
	bag.assign(N, 0);
	for(int i=0; i<N; i++) {
		pin >> bag[i];
	}
}

int max_val = 0;
void method(vector<int> S, vector<int> Q) {

	if(Q.size() == N) // get thr value 
	{
		int sum = 0;
		for(int i=0; i<Q.size()-1; i++) {
			sum += abs(Q[i]-Q[i+1]);
			cout << Q[i] << " "; 
			
		}
		cout << endl;
		Q.pop_back();
		if(sum > max_val ) max_val = sum;
	}

	for(int i=0; i<S.size(); i++) {
		bool flag = false;
		for(int j=0; j<Q.size(); j++) {
			if(S[i] == Q[j]) flag = true; 
		}
		
		if(!flag) {Q.push_back(S[i]);
		
			method(S, Q);}
	}	
}

int main() {
	input(cin);
	method(bag, bag2);
   cout << max_val << endl;	
	return 0;
}
