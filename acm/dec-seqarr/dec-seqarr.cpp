#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


std::vector<int> seq; // integer array for holding input array.
std::vector<std::vector<int> > table;

void input(istream& in) {
	int n;
	int temp;
	in >> n;
	
	for(int i=0; i<n; i++) {
		in >> temp;
		seq.push_back(temp);
	}
}

void init_table() {
	int l = seq.size();
	table.resize(l);
	
}

int method() {
	init_table();
	int l = seq.size();
	std::vector<int> sol_vec(l);
	for(int i=0; i<l; i++) {
		for(int j=0; j<i; j++) {
			if( (seq[j] > seq[i]) && (table[i].size() < table[j].size()+1)) {
				table[i] = table[j];
			}
		}
		table[i].push_back(seq[i]);
		sol_vec[i] = table[i].size();
	}
	auto biggest = std::max_element(std::begin(sol_vec), std::end(sol_vec));
	cout << *biggest << endl;
	return 0;
}

int main() {
	input(cin);
	method();
	
	// for(int i=0; i<seq.size(); i++) cout << table[i].size() << endl;
	return 0;
}
