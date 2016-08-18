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
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int sum = a + b + c + d;
	cin >> a >> b >> c >> d;
	int sum2 = a + b + c + d;
	int ans =  sum > sum2 ? sum : sum2; 
		cout << ans ;
	return 0;
}
