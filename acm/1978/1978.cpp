#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
/*
 * 에라토스테네스의 채를 이용한 소수 구하기 문제
 * sqrt(int) 가 2보다 작아지는 2 와 3 은 미리 처리하고 나머지는 sqrt(int) 만큼 루프를 순회하며 소수를 판정한다.
 * */
using namespace std;

int N;

vector<int> int_bag;
void input(istream& in) {
	in >> N;
	int temp;
	for(int i=0; i<N; ++i) {
		in >> temp;
		int_bag.push_back(temp);
	}
}

int method() {
	int cnt = 0;
	for(auto& it : int_bag) {
		if(it == 1) continue;
	    if(it== 2 || it == 3) {
			cnt++;
			continue;
		}
		for(int i=2; i<sqrt(it); i++) {
			if(it%i == 0) {
				break;
			}
			if(i == (int)sqrt(it)) {
				cnt++;
			}
		}
	}
	return cnt;	
}

int main() {
	input(cin);
	cout << method()<< endl;

	return 0;
}
