#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int x;
int y;
int w;
int h;

void input(istream& in) {
 	in >> x >> y >> w >> h;
} 

void method() {
	cout << min({(w-x), (h-y), x, y});
}

int main() {
	input(cin);
	method();
	return 0;
}
