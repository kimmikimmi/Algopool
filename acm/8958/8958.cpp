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
int T;
vector<string> ox_result;

void input(std::istream& pin) {
	pin >> T;
	ox_result.assign(T, "");
	for(int i=0; i<T; i++) 
		pin >> ox_result[i]; 
}

int method(string& target) {
	int acc = 0;
	int sum = 0;
	for(auto& it : target) {
		if(it == 'O') acc++;
		else acc = 0;
		sum += acc;
	}	
	return sum ;
}

int main() {
	input(cin);
	for(int i=0; i<T; i++) 
		cout << method(ox_result[i]) << endl;
	return 0;
}
