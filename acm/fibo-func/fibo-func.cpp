#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NUM 41

std::vector<int> input_set;

struct F_collection
{
	int value;
	int cnt_one;
	int cnt_zero;
	F_collection() : value(-1), cnt_one(0), cnt_zero(0) {}

};

F_collection cache[MAX_NUM];

void initialize_cache() {
	for(int i=0; i<MAX_NUM; i++) {
			cache[i].value = -1;
			cache[i].cnt_one = 0;
			cache[i].cnt_zero = 0;
	}

} 

void input(istream& in) {
	int n, temp;
	in >> n;
	for(int i=0; i<n; i++) {
		in >> temp;
		input_set.push_back(temp);
	}
}

F_collection fibo(int n) {
	if(cache[n].value != -1) return cache[n];
	if(n == 0) {
		cache[0].cnt_zero++;
		cache[0].value = 0;
		return cache[0];
	} else if(n == 1) {
		cache[1].cnt_one++;
		cache[1].value = 1;
		return cache[1];
	} else {
		cache[n].value = fibo(n-1).value + fibo(n-2).value;
		cache[n].cnt_one = fibo(n-1).cnt_one + fibo(n-2).cnt_one;
		cache[n].cnt_zero = fibo(n-1).cnt_zero + fibo(n-2).cnt_zero;
		return cache[n];
	}

}

int main() {
	initialize_cache();
	input(cin);
	for(auto k : input_set) {
		cout  << fibo(k).cnt_zero << " " << fibo(k).cnt_one << endl;
	}
	return 0;
}
