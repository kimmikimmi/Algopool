#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> divisors;

void input(istream& in) {
	in >> N;
	int temp;
	for(int i=0; i<N; i++) {
		in >> temp;
		divisors.push_back(temp);
	}
}
void method() {
	
	sort(divisors.begin(), divisors.end());
	cout << divisors[0] * divisors[divisors.size()-1];
}

int main() {
	input(cin);
	method();
	return 0;
}
