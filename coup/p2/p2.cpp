#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
/*
1. 검색단어, 검색횟수리스트를 저장할 자료구조 map<string, int>를 생성 및 read input
2. 같은의미 단어 조합수, 단어 조합리스트에 대해 vector<vector<string>> 를 생성
	아래와 같이 구성
	index content
	0	슬리퍼 -> 슬립퍼 -> 슬리뻐
	1	나이키 -> 나이크

3. 맵을 순회하며 벡터의 같은 인덱스에 있는 값들을 더해주며 출력.
*/

int num_of_words;
std::map<string, int> map;
int num_of_same;
std::vector<std::vector<string>> v;


void input(istream& in) {
	in >> num_of_words;
	string temp;
	for(int i=0; i<num_of_words; i++ ) {
		in >> temp;
		map[temp]++;
	}
	in >> num_of_same;
	string same; string same2;

	for(int i=0; i<num_of_same; i++) {
		int >> same >> same2;
		//....
	}

}
void method() {
}

int main() {
	return 0;
}

