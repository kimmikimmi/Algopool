
#include <iostream>
using namespace std;


double cache[101][101];

double combination(int n, int r) {

	if(cache[n][r] != -1) return cache[n][r];
	
	if(r == 0 || n == r) {
		cache[n][r] = 1; 
		return 1;
	}
	cache[n][r] = combination(n-1, r) + combination(n-1,r-1);

	return cache[n][r];
}


void setUpDynamic() {
	for(int i=0; i<101; i++) {
		for(int j=0; j<101; j++) {
			cache[i][j] = -1;
		}
	} 
}


int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin >> n;
	int m;
	cin >> m;
	setUpDynamic();
	cout << (int)combination(n,m);
	

	
	return 0;
}