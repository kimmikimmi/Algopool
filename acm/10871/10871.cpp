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
int X;
vector<int> nums;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> N >> X;
	int tmp;
	for(int i=0; i<N; i++) {
		cin >> tmp;
		if(tmp < X) nums.push_back(tmp);
	}

	for(auto& it : nums) 
		cout << it << " ";
	return 0;
}
