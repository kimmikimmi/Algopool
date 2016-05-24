#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int T;
std::vector<int> int_bag;

void input(istream& in) {
	int temp;
	in >> T;
	for(int i=0; i<T; i++)  {
		in >> temp;
		int_bag.push_back(temp);
	}
	
}



void method(std::vector<int> v) {
	 
	for(auto iter : v) cout << (int)sqrt(iter) << endl;

}

int main() {

	input(cin);
	method(int_bag);
	return 0;
}
