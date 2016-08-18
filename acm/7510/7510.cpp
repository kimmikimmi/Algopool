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
	int t;
	scanf("%d", &t);
	vector<int> tmp(3);
	for(int i=0; i<t; i++) {
		scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]);
		printf("Scenario #%d:\n", i+1);
		sort(tmp.begin(), tmp.end());
		if(tmp[2]*tmp[2] == tmp[0]*tmp[0] + tmp[1]*tmp[1])
			printf("yes\n") ;
		else 
			printf("no\n");
		printf("\n");
	}
	return 0;
}
