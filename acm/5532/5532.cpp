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
int L,A,B,C,D;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int days = 0;
	cin >> L >> A >> B >> C >> D;
	if(A%C == 0) {
		days = A/C;
	} else {
		days = A/C + 1;
	}
	if(B%D == 0) {
		if(days < B/D) days = B/D;
	} else {
		if(days < (B/D+1)) days = B/D+1;
	}
	cout << L - days ;
	return 0;
}
