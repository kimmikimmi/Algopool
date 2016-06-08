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
	int buf;
	int sum = 0;
	for(int i=0; i<5; i++) {
		cin >> buf;
		if(buf < 40) buf = 40;
		sum += buf;
	}
	cout << sum / 5 << endl;
	return 0;
}
