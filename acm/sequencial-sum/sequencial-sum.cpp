#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int size;
int* input_arr;
int* max_sum;
int* tmp_sum;

void input(istream& kimin) {
	kimin >> size;

	input_arr = new int[size];
	max_sum = new int[size];
	tmp_sum = new int[size];

	for(int i=0; i<size; i++) {
		kimin >> input_arr[i];
		max_sum[i] = 0;
		tmp_sum[i] = 0;
	}

}

void method() {

	max_sum[0] = input_arr[0];
	tmp_sum[0] = input_arr[0];

	for(int i=1; i<size; i++) {
		if(input_arr[i] <= 0) {
			max_sum[i] = max_sum[i-1];
			tmp_sum[i] = tmp_sum[i-1] + input_arr[i];
		} else {
			if(tmp_sum[i-1] > 0) {
				if(max_sum[i-1] > tmp_sum[i-1] + input_arr[i]) {
					max_sum[i] = max_sum[i-1];				
				} else {
					max_sum[i] = tmp_sum[i-1] + input_arr[i];
				}
				tmp_sum[i] = tmp_sum[i-1] + input_arr[i];
			} else {
				if(max_sum[i-1] >  input_arr[i]) {
					max_sum[i] = max_sum[i-1];
				} else {
					max_sum[i] = input_arr[i];
				}
				tmp_sum[i] = input_arr[i];
			}
		}
	}

}

int main() {
	input(cin);
	method();
	cout << max_sum[size-1];
	//for(int i=0; i<size; i++) cout << input_arr[i] << "  " << max_sum[i] << "  " << tmp_sum[i] << endl;
	return 0;
}

