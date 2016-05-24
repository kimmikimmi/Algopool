#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int r1;
int s;

void input(istream& in) {
	in >> r1 >> s;
}

int method() {
    return s*2 - r1;
}

int main() {
	input(cin);
	cout << method() << endl;
	return 0;
}
