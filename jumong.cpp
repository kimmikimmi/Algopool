#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//Inline functions
inline void print(std::vector<int> v) {
	for(auto iter=v.begin(); iter!=v.end(); iter++) cout << *iter << endl;
}


//Global variables.
int numOfElements; // 고유 재료의 개수
vector<int> elements;
int m; // 갑옷을 만드는데 필요한 숫자


// functions..
int func() {
	int cnt = 0;
	int j = 0;
	sort(elements.begin(), elements.end());
	
	//print(elements);
	for(auto i=0; i<numOfElements; i++) {
		for(int j=numOfElements-1; j!=i; j--) {
			if(elements[i] + elements[j] < m ) continue;
			if(elements[i] + elements[j] == m ) cnt++; 
		}	
		
	}
	return cnt;
}

int insert() {
	int element = 0;
	if(numOfElements == 0) return 0;
	for(int i=0; i<numOfElements; i++) {
		cin >> element;
		elements.push_back(element);
	}
	return 1;
}


int main(int argc, char const *argv[])
{
	
	cin >> numOfElements;
	cin >> m;
	insert();
	//print(elements);
	cout  << func();
	return 0;
}