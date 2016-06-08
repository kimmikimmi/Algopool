#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int N;

void input(istream& in) {
	in >> N;
}

long long method(int i) {
	return ((1.5)*i*i)  + (2.5)*i +1;
}

int main() {
	input(cin);
	cout << method(N)%45678 << endl;
	return 0;
}
