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
vector<int> line;
vector<int> cache; 

void input(std::istream& pin) {
	pin >>N;

	int tmp;

	for(int i=0; i<N; i++) {
		pin >> tmp;
		line.push_back(tmp);
		cache.push_back(tmp);		
	}

	

}

int method() {
	sort(line.begin(), line.end());
	sort(cache.begin(), cache.end());
	int sum = cache[0];
	for(int i=1; i<N; i++) {
		cache[i] = cache[i-1] + line[i];
		sum += cache[i];
	}

	return sum;
}

int main() {
	input(cin);
	cout << method() << endl;
	return 0;
}




