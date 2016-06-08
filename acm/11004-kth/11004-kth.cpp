#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int N;
int K;
vector<int> seq;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int tmp;
	scanf("%d %d", &N, &K);
	seq.assign(N, 0);

	for(int i=0; i<N; i++) { 
		scanf("%d", &tmp);
	    seq[i] = tmp;	
	}
	
	nth_element(seq.begin(), seq.begin()+K-1, seq.end());

	std::cout << seq[K-1] << std::endl;
	
	return 0;
}
