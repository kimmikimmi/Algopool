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


void input(std::istream& pin) {

}

int method() {
	return 0;
}
#define AGREEMENT "Junhee is cute!"
#define DISAGREEMENT "Junhee is not cute!"

int main() {
	int N;
	std::cin >> N;
	int tmp;
	int one_cnt = 0;
	for(int i=0; i<N; i++) {
		std::cin >> tmp;
		if(tmp == 1) one_cnt++;
	}
	if(one_cnt*2 > N ) std::cout << AGREEMENT << std::endl;
	else
		std::cout << DISAGREEMENT << std::endl;
	return 0;
}
