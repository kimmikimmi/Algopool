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
	int tmp;
	for(;;) {
		in >> tmp;
		if(tmp == 0 ) break;
		int_bag.push_back(tmp);
	}
}
void isMultiple(int& i) {
	if(i%n == 0) cout << i << " is a multiple of "<< n<< "."<< endl;
	else 
		cout << i << " is NOT a multiple of "<< n <<"." <<  endl; 
}
void method() {

	for_each(int_bag.begin(), int_bag.end(), isMultiple);
}

int main() {
	input(cin);
	method();
	return 0;
}
