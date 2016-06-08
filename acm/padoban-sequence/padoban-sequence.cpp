#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int num_testcases;

vector<int> padoban_seq;

vector<int> keys;
void input(istream& in) {
	in >> num_testcases;
	int temp;
	for(int i=0; i<num_testcases; i++) {
		in >> temp;
		keys.push_back(temp);
	}

}

void method(int n) {
	padoban_seq.clear();
	padoban_seq.push_back(0);
	padoban_seq.push_back(1);
	padoban_seq.push_back(1);
	padoban_seq.push_back(1);
	for(int i= 4; i<=n; i++) {
		int a = padoban_seq[i-2] + padoban_seq[i-3];
		padoban_seq.push_back(a);
	}
//i	for(auto& it : padoban_seq) cout << it << endl;	
	cout << padoban_seq[n] << endl;
}

int main() {
	input(cin);
	for(auto& iter : keys) {
		method(iter);
	}
	
	return 0;
}
