#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

#define ASC "ascending"
#define DSC "descending"
#define MIX "mixed"

int a[8];

void input(istream& in) {
	int buf;
	for(int i=0; i<8; i++) {
		in >> buf;
		a[i] = buf;	
	}
}

int main() {
	input(cin);
	int asc_cnt = 0;

	for(int i=1; i<8; i++) {
		if(a[i-1] < a[i]) asc_cnt++;
		else
			asc_cnt--;
	}

	if(asc_cnt == 7) cout << ASC;
	else if(asc_cnt == -7) cout << DSC;
	else 
		cout << MIX;

	return 0;
}
