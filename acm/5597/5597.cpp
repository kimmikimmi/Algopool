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
	bool bitmap[30] = {false};
	int buf;
	for(int i=0; i<28; i++) {
		cin >> buf;
		bitmap[buf-1] = true;
	}	
	for(int i=0; i<30; i++) 
		if(!bitmap[i]) cout << i+1 << endl;
	return 0;

}
