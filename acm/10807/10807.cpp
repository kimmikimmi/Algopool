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
int v;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> N;// 정수의 개수 
	vector<int> bag(201,0);
	int tmp;
	for(int i=0; i<N; i++) {
		cin >> tmp;
		bag[tmp+100]++;
	}
	cin >> v;
	cout << bag[v+100] << endl;
	return 0;
}
