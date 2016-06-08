#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;


void input(istream& in) {

}

void method() {

}

int main() {
	float a,b,c,d;
	float f;
	scanf("%f %f %f", &a, &b, &c);
	f = sqrt(c*c+b*b);
	printf("%d %d", (int)(a*b/f), (int)(a*c/f));
	return 0;
}
