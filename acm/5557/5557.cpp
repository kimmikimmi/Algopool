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

int N;
long long cache[21][101];

void input(std::istream& pin) {
	pin >> N;
}

int main() {
	input(cin);

	int buf;
	cin >> buf;
	cout <<"\t";
	cout << buf << "\t";
	cache[buf][1] = 1;
	
	for(int i=2; i<N; i++) {
		cin >> buf;
		cout << buf << "\t";
		for(int j=0; j<21; j++) {
			if(cache[j][i-1] != 0) {
				 if( j + buf <= 20) 
					cache[j + buf][i] += cache[j][i-1];
			     if (j - buf >= 0) 
					cache[j - buf][i] += cache[j][i-1];	
			}
		}
	}

	cin >> buf;
	cout << "= " << buf << endl;
	for(int i=0; i<21; i++) {
		cout << i << "\t";
		for(int j=1; j<11; j++) {
			cout << cache[i][j]  << "\t";
		}
		cout << endl;
	}	

	cout << cache[buf][N-1];
	return 0;
}
