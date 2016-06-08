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


void input(std::istream& pin) {

}

int method() {
	return 0;
}
using namespace std;
int main() {
	int a,b,c;

	cin >> a >> b >> c;
	int sum = a + b + c;
	if(sum != 180 ) 
		cout << "Error" << endl;
	else if(a == 60 && b == 60) 
		cout << "Equilateral" << endl;
	else if(a == b || a == c || b == c) 
		cout << "Isosceles" << endl;
	else 
		cout << "Scalene" << endl;
	return 0;
}
