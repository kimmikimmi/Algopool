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

int method(int n) {
	int highest = 0;
	vector<int> locations;
	for(int i=0;;i++) {
		if(pow(2,i) > n) {
		   highest = i-1;
		   break;
		}	   
	}
	for(int i= highest; i>=0; i--) {
		if(n >= pow(2,i)) { 
			locations.push_back(i);
			n -= pow(2,i);
		}
	}
	sort(locations.begin(), locations.end());
	for(auto& it : locations) cout << it << " " ;
	return 0;
}

int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int tmp;
		cin >> tmp;
		method(tmp);
		cout << endl;
	}
	return 0;
}
