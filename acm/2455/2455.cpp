#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <tuple>
#include <set>

using namespace std;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int _max = 0;
	int population = 0;
	for(int i=0; i<4; i++) {
		int a, b;
		cin >> a >> b;
		population +=  (-a + b);
		if(_max < population) _max = population; 
	}
	cout << _max;
	return 0;
}
