
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
using namespace std;

int n;
vector<int> int_bag;
void input(istream& in) {
	in >> n;
	int temp = -1;	
    for(int i=0; temp != 0; i++) {
		in >> temp;
		if(temp == 0) break;
		int_bag.push_back(temp);
	}
}


void method() {
	for(auto it : int_bag) {
		if(it % n == 0) cout << it << " is a multiple of " << n << "." << endl;

		else 
			cout << it << " is NOT a multiple of " << n << "." << endl;
	}
}

int main() {
	input(cin);
	method();
	return 0;

}


