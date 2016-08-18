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
	vector<int> W(10);
	vector<int> K(10);
	for(int i=0; i<10; i++) 
		cin >> W[i];
	for(int i=0; i<10; i++)
		cin >> K[i];
	sort(W.begin(), W.end());
	sort(K.begin(), K.end());

	cout << W[7] + W[8] + W[9] << " " << K[7] + K[8] + K[9] << endl;

	return 0;
}
