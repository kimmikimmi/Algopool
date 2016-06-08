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
vector<int> yogurts;

void input(std::istream& pin) {
	pin >> N;
	int tmp;
	for(int i=0; i<N; i++) {
	   pin >> tmp;
	   yogurts.push_back(tmp);
	}	   
}

int method() {
	sort(yogurts.begin(), yogurts.end(), [](int a, int b) {return a > b;});
	int num_loops = N/3;
	int rest = N%3;
	int result = 0;
	int i;
	for(i=0; i<num_loops; i++) {
		int min_yogurt = min({yogurts[i*3], yogurts[i*3+1], yogurts[i*3+2]});
		result += yogurts[i*3] + yogurts[i*3 +1] + yogurts[i*3 + 2] - min_yogurt; 	
	}

	for(int j=0; j<rest; j++) {
		result += yogurts[i*3+j];  
	}

	return result;
}

int main() {
	input(cin);
	cout << method() << endl;
	return 0;
}
