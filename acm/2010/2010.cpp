#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int N;


void input(istream& in) {

}

void method() {

}

int main() {
	cin >> N;
	int sum;
	int tmp;
	for(int i=0; i<N; i++) {
	   cin >> tmp;
		sum += tmp;
	}
	cout << sum - N+1 << endl;	
	return 0;
}
