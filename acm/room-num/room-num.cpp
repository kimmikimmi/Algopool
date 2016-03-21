#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
/*
Prob Descriptiion : 
시간 제한	메모리 제한	
2 초	128 MB	

문제
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최소값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)


입력
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.
출력
첫째 줄에 필요한 세트의 개수를 출력한다.
*/

string room_num; // std::in으로 부터 입력을 읽어오는 자료구조, 방번호를 저장한다.
map<char, int> setCounting; // <char , int > 가 각각의 char ('0' to '9') 가 각각 스트링에서 몇개가 있는지 저장한다.


/*
@Description : While traversing through room_num string, embed numbers of each char '0' to '9'
				However, in case of '6' and '9' it is considered as same number here, and for the answer, manupulate setCounting['6'] a bit.
@param : null
@return : null

*/
void mapCount() {
	for(auto& p : room_num) {
		if(p == '9') {
			setCounting['6']++;
			continue;
		}
		setCounting[p]++;
	}

	setCounting['6'] -= setCounting['6'] / 2;
}

/*
@Description : simple function to display the map
@param : null
@return : null
*/
void displayMap() {
	for(auto it : setCounting) cout << it.first << " " << it.second << endl;
}

/*
@Description : boolean function to compare two value_type.second in map.
			wrote it in order to use std::find function.
@param : map<char, int>::value_type&, map<char, int>::value_type&
@return : bool
*/
bool value_comparer(map<char, int>::value_type &i1, map<char, int>::value_type &i2)
{
return i1.second < i2.second;
}


/*
@description : method to find solution using std::max_element with setCounting.
@param : null
@return : integer : # of max count in setCounting.
*/
void method() {
	mapCount();
	// displayMap();
	auto max_set = max_element(setCounting.begin(), setCounting.end(), value_comparer);
	cout << max_set->second << endl;
}

int main() {
	cin >> room_num;
	method();

	return 0;
}
