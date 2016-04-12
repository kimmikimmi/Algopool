#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//7570
std::vector<int> seq; // integer array for holding input array.

std::vector<int> sol_vec;

int n;
void input(istream& in) {
	
	int temp;
	in >> n;
	seq.push_back(-1);

	for(int i=0; i<n; i++) {
		in >> temp;
		seq.push_back(temp);
		
	}
	sol_vec.resize(n+1);
}

void method() {
	int len = seq.size();
	for(int i=1; i<len+1; i++) {
			sol_vec[seq[i]]++;


			
			auto iter = find(seq.begin(), seq.end(), seq[i]-1 );
			// if(sol_vec[seq[i]-1] != 0) { // 만약 해당 원소가 0이 아니면
			if(iter != seq[i]) {
				sol_vec[seq[i]] += sol_vec[seq[i]-1];
			}
				
			
	}
}

int main() {
	input(cin);
	method();
	cout << " ind : ";
	for(int i=0; i<seq.size(); i++) cout << i << " ";
		cout << "-----" << endl;
	cout << "seq : ";
	for(auto k : seq) cout << k << " ";
		cout << "-----" << endl;
	cout << " sol : " ;
	for(auto k : sol_vec) cout << k << " ";
		cout << "---" << endl;
	cout << * max_element(std::begin(sol_vec), std::end(sol_vec));
	return 0;
}
