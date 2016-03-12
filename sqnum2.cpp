/*
coded by Hyeonjun Kim
	12nd. March. 2016
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

// data structure for DP
// a has the results of the sum of full squares.
vector<int> a; 
int arr[100000];
int methodSub(int n);
/*
Description : deal with input and calls methodSub
@param : 
		n (integer)
*/
void method(int n) {
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	arr[0] = 0; arr[1] = 1; arr[2] = 2;
	for(int i=3; i<100000; i++) arr[i] = 100000;
	cout <<methodSub(n);
}

/*
Description : recursion + dynamic programming
				methodSub(n) returns the minimum number of the sum of full squares.
				min : minimum number of methodSub(n)
				max : maximum number among square roots less than n
				i : index which iterates to max
@param : n
@return : minimum number of the sum of perfect squares.

*/
int methodSub(int n) {
	
	if(arr[n] != 100000) return arr[n];

	int max = (int)sqrt(n);
	if(n==0 || n==1 || n==2) {
		return n;
	}
	

	for(int i=max; i>0; i--) {
		// cout << i << endl;
		int originNum = (int)pow(i,2);
		
		if(arr[n] > methodSub(n-originNum) + 1) {
			arr[n] = methodSub(n-originNum) + 1;
		}

	}

	
	return arr[n];
		
}

int main(int argc, char const *argv[])
{
	int input;
	cin >> input;
	 method(input);


	return 0;
}








