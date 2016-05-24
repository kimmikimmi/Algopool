#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string str; // 입력받은 문자열을 저장합니다
map<char, int> fridge; // 입력받은 문자열에서 각각의 케릭터가 몇개씩 들어있는지 저장하고 있는 자료구조입니다.
vector<pair<char, int>> v;

// 값을 읽어와 str에 저장합니다.
void input(istream& in) {
	in >> str;
}


// str을 순회하며 p 마다 카운트를 증가시켜 각각에 몇개씩 들어있는지 저장합니다.
void set_map_count(string str) { 
	int i=0;
	for(auto& p : str) {
		fridge[p]++;
	}
}

// 답을 계산 / 출력하는 함수입니다.
void method() {
	string answer;
	std::vector<pair<char, int>> pairs;
	// fringe를 순회하며 각각의 pair를 pairs에 저장합니다( std:sort를 이용하기 위해)
	for (auto  it : fridge)
    	pairs.push_back(it);

    // pair<char, int> 의 int에 대해 오름차순 정렬합니다.
	sort(pairs.begin(), pairs.end(), [=](pair<char, int>& a, pair<char, int>& b) {
	    return a.second < b.second;
	});
 	
	
	for(auto it : pairs) {
		for(int j=0; j<it.second; j++) {
			answer += it.first;
		}
	}
	cout << answer;
}


int main() {
	input(cin); 
	set_map_count(str);
	method();
		
	return 0;
}
