#include <iostream>
#include <vector>
#include <algorithm>


//#include <list>

using namespace std;


string target_str; // 1~100만 길이의 input를 임시로 저장하는 스트링
string expl_str; // 1~ 36 길이의 input를 임시로 저장하는 스트링

std::vector<char> v; // target_Str을 처리하기 위한 링크드 리스트..

std::vector<char> mystack; // 알고리즘을 위한 개념적 스택

// string의 각 char들을 v에 저장

void set_elements() {
	for(char iter : target_str) v.push_back(iter);
}


// std:in으로 부터 값을 읽어서 저장.
int input() {
	
	cin >> target_str;
	cin >> expl_str;
	return 0;
}

void displayStack();


int method() {
	set_elements();

	int cursor = 0;
	int repeated = 0;
	int cnt =0;

	if(expl_str.size() == 1) {
		//remove(v.begin(), v.end(), expl_str[0]);
		for(auto iter=v.begin(); iter!=v.end(); iter++) {
			if(*iter == expl_str[0]) {
				v.erase(iter);
				iter--;
			}
		}
		return 0;
	}


	for(auto iter=v.begin(); iter!=v.end(); iter++, cnt++) {
		
		if(mystack.empty()) {			
			if(*iter == expl_str[0]) {
				mystack.push_back(*iter);				
				cursor++;
				// displayStack();
				// cout << cnt << endl;
			}
			continue;
		}



		if(*iter == mystack.back() && mystack.back() == expl_str[0]) { // 스텍.top()이 폭발 문자열의 첫번째 원소와 동일한 경우..
			// cout << "중복 삽입 "			<< endl;
			repeated++;
			mystack.push_back(*iter);
			
		} else if(mystack.back() == expl_str[cursor-1]) {			
			if(expl_str[cursor] == *iter) {
				if(cursor == expl_str.size()-1) { // 폭발 문자열의 마지막이라면..
					
					for(int i=0; i<expl_str.size()-1; i++) {
						mystack.pop_back();
						iter--;				
					}

					if(repeated != 0) { 
						cursor = 1; repeated--;
					} else cursor = 0;
			

					v.erase(iter, iter + expl_str.size());
	
					for(int i=0; i<expl_str.size()-1; i++) iter--;					
				} else {
					mystack.push_back(*iter);
					cursor++;
				}
				
				
			} else {
			mystack.clear();
			cursor = 0;
		}
			
		
		} else {
			mystack.clear();
			cursor = 0;
		}
	}
	return 0;
	
}

void displayStack() {
	cout << "stack elements------------------------------------------------" << endl;
	for(auto & iter : mystack) cout << iter << endl;
	cout << "-------------------------------------------------------------"<< endl;
}




int main() {
	input();
	method();
	// cout << target_str << endl;
	if(v.size() == 0) cout << "FRULA" << endl;
	else {
		for(auto iter : v) cout << iter ;
	}
	return 0;
}



// #include <iostream>
// #include <string.h>
// using namespace std;

// char Text[1000001], Bomb[37], Stack[1000001], Bomb_Last;
// int Point, Bomb_Size;

// int main() {
//     cin >> Text >> Bomb;
    
//     Bomb_Size = strlen(Bomb);
//     Bomb_Last = Bomb[Bomb_Size-1];
//     int text_size = strlen(Text);
    
//     for (int i = 0; i < text_size; i++) {
//         Stack[Point++] = Text[i];
//         if (Point >= Bomb_Size && Text[i] == Bomb_Last) {
//             int j, k;
//             for (j = Point-1, k = Bomb_Size - 1; k >= 0; j--, k--) 
//                 if (Stack[j] != Bomb[k]) break;
//             if (k == -1) Point -= Bomb_Size;
//         }
//     }

//     if (Point == 0) cout << "FRULA" << endl;
//     else {
//         for (int i = 0; i < Point; i++)
//             cout << Stack[i];
//         cout << endl;
//     }

// }
