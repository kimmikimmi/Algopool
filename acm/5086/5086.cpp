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

int method(int a, int b) {
	int gcd = __gcd(a,b);
	if(gcd == a) cout << "factor" << endl;
	else if(gcd == b) cout << "multiple" << endl;
	else 
		cout << "neither" << endl;	
	return 0;
}

int main() {
	int f_num, s_num;
	for(;;) {
		cin >> f_num >> s_num;
		if(f_num == 0 && s_num == 0) break;
		method(f_num, s_num);
	}
	return 0;
}
