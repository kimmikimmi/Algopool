#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int n;
std::vector<long long int > int_bag;

void input(istream& in) {
	in >> n;
	vector<unsigned long long> vi(n+1);
	vi[0] = 0;
	vi[1] = 0;
	vi[2] = 1;
	vi[3] = 2;
	for (int i = 3; i <= n; ++i)
	{
		unsigned long long temp;
		temp = (vi[i-2] + vi[i-1]) % 1000000000;
		temp *= (i-1);
		temp %= 1000000000;
		vi[i] = temp;
	}
	cout << vi[n];
}

int main() {
	input(cin);
	return 0;
}
