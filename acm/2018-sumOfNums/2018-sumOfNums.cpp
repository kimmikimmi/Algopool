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

void method() {
	int cnt = 0;
	int tmp = 0;
	for(int i=1;;++i) {
		tmp = N - i*(i-1)/2;
		if(i > tmp) break;
		if(tmp%i == 0) cnt++;
	}
	cout << cnt << endl;
}

int main() {
	input(cin);
	method();
	return 0;
}
