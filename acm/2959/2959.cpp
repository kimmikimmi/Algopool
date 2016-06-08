#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

vector<int> edges;
void input(istream& in) {
	int edge;
	for(int i=0; i<4; i++) {
		in >> edge;
		edges.push_back(edge);
	}
}

void method() {
	sort(edges.begin(), edges.end());
	cout << edges[0]*edges[2] << endl;
}

int main() {
	input(cin);
	method();
	return 0;
}
