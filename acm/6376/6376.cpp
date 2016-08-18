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

double factorial(int n) {
	if(n == 0) return 1;
	if(n == 1) return 1;
	return n*factorial(n-1);
}

int main() {
	cout << "n e" << endl;
    cout << "- -----------" << endl;	
	double sum = 0;
	for(int i=0; i<10; i++) {
		sum += 1/factorial(i);
		if(i==0) 
			cout << i << " " << 1 << endl; 
		else if ( i == 1) 
			cout << i << " " << 2 << endl;
		else if ( i == 2) 
			cout << i << " " << 2.5 << endl;
		else { 
			printf("%d %.9f\n", i,  sum);
		}
	}
	return 0;
}
