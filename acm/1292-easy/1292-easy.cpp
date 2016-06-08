#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;
#define LAST_ELEMENT 45
vector<int> prob_seq;

int begin_index;
int end_index;

void input(istream& in) {
	in >> begin_index >> end_index;
}

void method() {
	for(int i=1; i<=LAST_ELEMENT; ++i) 
		for(int j=0; j<i; ++j)
			prob_seq.push_back(i);
	
}

int find_solution(int b, int e) {
	int sum = 0;
	for(int i=b-1; i<e; i++) {
		sum += prob_seq[i];
	}
	return sum;
}

int main() {
	input(cin);
	method();
	// for(auto& it : prob_seq) cout << it << endl;
	cout << find_solution(begin_index, end_index) << endl;
	return 0;
}
