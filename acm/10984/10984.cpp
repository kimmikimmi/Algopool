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

int T;
void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> T;
	int N;
	int C;
	double G;
	int credits;
	double grade;
	for(int i=0; i<T; i++) {
		cin >> N;
		credits = 0;
		grade = 0;
		for(int j=0; j<N; j++) {
			cin >> C >> G;
			credits += C;
			grade += G*C;
		}
		printf("%d %.1f \n", credits, grade/credits); 
	}
	return 0;
}
