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

int main() {
	int n;
	std::cin >> n;
	int factorial = 1;
	for(int i=2; i<=n; i++)
	   factorial *= i;
	std::cout << factorial << std::endl;	
	return 0;
}
