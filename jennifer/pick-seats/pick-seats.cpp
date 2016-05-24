#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define OCCUPIED 0
#define AVAILABLE 1

/*
	문제가 직접 두번의 for loop을 반복하여도 O(n^2)의 시간복잡도를 가져 충분하다고 판단, 직접 순회하였습니다.
*/

vector<vector<int>> poss_seats; // 모든 가능한 자리를 표시하는 자료구조
int n; // 좌석의 가로 세로의 길이


// 값을 읽어와 저장합니다.
void input(istream& in) {
	
	char temp;
	in >> n;
	poss_seats.resize(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			in >> temp;
			if(temp == '*')
				poss_seats[i].push_back(OCCUPIED);
			else 
				poss_seats[i].push_back(AVAILABLE);
		}
	}
}

// 모든 가능성을 검색하여 값을 출력합니다.
void method() {
	int answer = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-1; j++) {
			if(poss_seats[i][j] == AVAILABLE && poss_seats[i][j+1] == AVAILABLE) {
				answer++;
			}	
		}
	}
	cout << answer << endl;
}

int main() {
	input(cin);
	method();
	return 0;
}
