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
	int a,b,c;
	cin >> a >> b >> c;
	if( a== b && b== c) cout << 10000 + a*1000 << endl;
	else if( a==b) cout << 1000 + a*100 << endl;
	else if( b==c) cout << 1000 + b*100 << endl;
	else if(a ==c) cout << 1000 + c*100 << endl;
	else {
		vector<int> d;
		d.push_back(a);
		d.push_back(b);
		d.push_back(c);
		sort(d.begin(), d.end());
		cout << d[2] * 100 << endl;
	}	


	return 0;
}
