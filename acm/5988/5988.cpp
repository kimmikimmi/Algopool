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

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		string testcase;
		cin >> testcase;
		if((testcase[testcase.size()-1] - '0')%2 == 0) cout << "even" << endl;
		else 
			cout << "odd" << endl;	
	}
	return 0;
}
