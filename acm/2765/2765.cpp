#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
#define ROUNDING(x, dig) (floor((x) * pow(10, dig) + 0.5f) / pow(10, dig))
int main() {
	int n, i;
	double inch,k;


	i = 0;

	while(1) {
		i++;
		cin >> inch >> n >> k;
		if(n==0) return 0;
		printf("Trip #%d: %.2lf %.2lf\n", i, inch*n*3.1415926535/63360, inch*n/k*3.1415926535/63360*3600);
	}
	return 0;
}
