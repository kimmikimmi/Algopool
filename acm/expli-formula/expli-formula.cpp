#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int size;
std::vector<int> fringe;
std::vector<int> tmp_fringe;
std::vector<int> p;
void input(istream& in) {
	in >> size;
	int tmp;
	for(int i=0; i<size; i++) {
		in >> tmp;
		fringe.push_back(tmp);
	}
	tmp_fringe.resize(size);
	copy(fringe.begin(), fringe.end(), tmp_fringe.begin());

	std::sort(tmp_fringe.begin(), tmp_fringe.end());

}

void method() {
	p.resize(size);
	// for(auto k : tmp_fringe) cout << k << " " << endl;
	int cnt = 0;
	for(int i=0; i<size; i++) {
		
		for(int j=0; j<size; j++) {
			if(tmp_fringe[j] == fringe[i]) {
				p[i] = j;
				tmp_fringe[j] = -1;
				break;
			}
		}
	}

	for(auto it : p) cout << it << " ";
}

int main() {
	input(cin);
	method();
	
	// for(auto k : fringe) cout << k << endl;
	return 0;
}
