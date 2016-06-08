#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <stdio.h>

using namespace std;

int N;

void input(istream& in) {
	in >> N;
}

// O(N)
long long find_sol_constraintA(int a) {
	long long result = 0;
	if(a<=2) return 0;

	for(int i=a; i>2; --i) {
		if(i%2 == 0) {
			result += i/2-1;			
		} else {
			result += i/2;
		}
	}
	return result;

}


//
int find_sol_constraintB(int b) {
	vector<int> divisors;
	int result = 0;
	for(int i=1; i<=(int)sqrt(b); i++) { 
		if(i*i == b) {
			divisors.push_back(i);
			
		} else if(b%i == 0) {
			divisors.push_back(i);
			divisors.push_back(b/i);
		}
	}

	sort(divisors.begin(), divisors.end());
//	for(auto& it : divisors) cout <<"divisors"<< it << endl;
	int size = divisors.size();
	for(int i=1; i<size; ++i) {
		for(int j=i-1; j >=0 && divisors[j]>= divisors[i]/2 ; j--) {
			for(int k=0; k<=j; k++) {
				if(divisors[k] + divisors[j] == divisors[i]) {

			//cout << "divisors["<<  i << "] = " << divisors[i] << " divisors["   << j << "] =  " << divisors[j] << " "<< divisors[k]<< endl;
					result++;
					break;
				}
			}
		}
	}

	return result;
}

int find_sol_constraintC(int c) {
	int result = 0;
	
	//bool prime[c+1];
	//memset(prime, true, sizeof(prime));
	vector<bool> prime(c+1, true);

	for(int p=2; p*p<=c; p++) {
		if(prime[p]) {
			for(int i=p*2; i<=c; i+=p) prime[i] = false;
		}
	}

	for(int p=2; p<=c-2; p++) 
		if(prime[p] && prime[p+2])  result++;
	
	return result;
}



int main() {
	input(cin);
	cout << find_sol_constraintA(N) << endl;
	cout << find_sol_constraintB(N) << endl;
	cout << find_sol_constraintC(N) << endl;
	return 0;
}
