#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void method() {
}

int main() {
	clock_t beg = clock();
	int a = 0;
	for(int i=0; i<300000; i++) {
		for(int j=0; j<100; j++) {
			a++;
		}
	}
	cout << float(clock() - beg) / CLOCKS_PER_SEC << endl;
	return 0;
}
