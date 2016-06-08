#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;


int T;
vector<int> fringe;

void input(istream& in) {
	in >> T;
	int tmp;
	for(int i=0; i<T; i++) {
		in >> tmp;
		fringe.push_back(tmp);
	}
}

void method(int n) {
	for(int i=2; ;i++) {

		int step = n-(i-1)*i/2;
		if(i>step) break;
		if(step%i == 0) {
			cout << n << " = " << step/i ;
			for(int j=1; j<i; j++)
				cout  << " + " << step/i + j ;
			cout << endl;
			return;
		}	
	}
	cout << "IMPOSSIBLE" << endl;
}

int main() {
	input(cin);
	for(auto& it : fringe) method(it);
	return 0;
}
