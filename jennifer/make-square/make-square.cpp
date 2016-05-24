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

// 거듭 제곱의 수로 표현되는지 검사합니다.
void method() {
	
	
	int q = 0;
	for(int i=2; i<sqrt(N); i++) {
		int temp = N;
		int mod;
		 while(true) {
			mod =  temp %i;
			temp /= i;
			cout << "i = " << i << "temp = " << temp  << "mod = " << mod << endl;
			if(mod != 0) {
				break;
			} else {
				q++;
			}
		 }
	}
	cout << q << endl;
}

int main() {
	input(cin);
	method();
	return 0;
}
