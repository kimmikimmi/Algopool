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
vector<int> seq;
void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int tmp;
	scanf("%d", &N);
	seq.assign(N, 0);
	for(int i=0; i<N; i++) {
		scanf("%d", &tmp);
		seq[i] = tmp;
	}
	sort(seq.begin(), seq.end(), [](int a, int b) {return a>b;});
	for(auto& it : seq) 
		printf("%d \n", it);

	return 0;
}
