#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;
unsigned long long int binomialCoeff(int n, int k);

void input(istream& in) {
	int T;
	in >> T;
	while(T--) {
		int n;
		in >> n;
		++n;
		cout << binomialCoeff(9+n-1,n-1) << endl;

	}
	
}

// Returns value of Binomial Coefficient C(n, k)
unsigned long long int binomialCoeff(int n, int k)
{
    unsigned long long int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;
 
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}

void method() {

}

int main() {
	input(cin);
	return 0;
}
