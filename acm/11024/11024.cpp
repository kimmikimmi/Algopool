#include <iostream>
#include <sstream>
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
	string t;
	getline(cin, t);
	int N = stoi(t);
	for(int i=0; i<N; i++) {
		string tmp;
		getline(cin, tmp);
		stringstream iss(tmp);
		int isum = 0;
		int t;
		while(iss >> t) {
			isum += t;
		}
		cout << isum << endl;
		string acc = "";
		vector<string> bag;
		for(auto& it : tmp) {
			if(it == ' ') {
				bag.push_back(acc);
				acc = "";
			} else {
				acc += it;
			}
		}
		bag.push_back(acc);
		int sum = 0;
		for(auto& it : bag) {
			//cout << it  << "\n";		
		}

		bag.pop_back();
		for(auto& it : bag) {
			sum += stoi(it);
		}
		//cout << sum << endl;
	}
	return 0;
}
