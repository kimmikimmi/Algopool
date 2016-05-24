#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define JENNIFERSOFT "JENNIFERSOFT"

/*
입력 문자열의 길이를 len이라고 할떄,
O(len*12+ len)의 시간복잡도.
*/

string str;

// 값을 읽어와 str 전역변수에 저장합니다.
void input(istream& in) {
	in >> str;
}

// 최소변경횟수를 계산하여 그 값을 리턴합니다.
//Levenshtein 거리 알고리즘을 사용하였습니다.
/*
	s1 을 제거, 추가, 치환하여 s2로 바꾸는 횟수를 리턴합니다.
*/
int min_manipulation(const string& s1, const string& s2)
{
	const int size1 = s1.size(), size2 = s2.size(); // 여러번 호출 되므로 미리 선언하여 사용 

	vector<vector<int>> cache(size1+1, vector<int>(size2+1)); 

	cache[0][0] = 0;
	for(int i=1; i<=size1; i++) cache[i][0] = i; //O(size1)
	for(int i=1; i<=size2; i++) cache[0][i] = i; //O(size2)

	for(int i=1; i<=size1; i++) //O(size1*size2)
		for(int j=1; j<=size2; j++) {
			cache[i][j] = min({cache[i-1][j]+1, cache[i][j-1]+1, cache[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1)});
		}
            
	return cache[size1][size2];
}

int main() {
	input(cin);
	cout << min_manipulation(str, JENNIFERSOFT);
	return 0;
}
