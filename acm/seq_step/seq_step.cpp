#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define COL_LEN 101
#define ROW 10
#define mod 1000000000
int n;
int cache[10][101];


void input(istream& wk) {
	wk >> n;
	//cout << n;
	// cache = new int *[ROW];
	// for(int i=0; i<ROW; i++) {
	// 	cache[i] = new int[n+1];
	// }

	for(int i=0; i<ROW; i++)
		for(int j=0; j<101; j++)
			cache[i][j] = 0;
}


int method(int i, int len) {

	 // cout << i<< ": " <<len<<"here" << endl;
	if(i == 10 || i == -1) return 0;

	if(len == 1) return cache[i][len] = 1;

	if(cache[i][len] != 0) return cache[i][len];

	return cache[i][len] = method(i-1, len-1)%mod + method(i+1, len-1)%mod;

}

int main() {
	int tmp;
	input(cin);
	int sum = 0;
	for(int i=1; i<10; i++) {
		// cout << sum << endl;
		tmp = method(i,n);
		tmp %= mod;
		sum += tmp;
		 sum %= mod;
	}
	cout << sum << endl;

	// for(int i=0; i<10; i++) {
	// 	cout << i << " :  ";
	// 	for(int j=0; j<n+1; j++) cout << cache[i][j] << " ";
	// 		cout << endl;
	// }
	return 0;
}
