#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> strings; // 전체 스트링 수식들을 저장하는 벡터
int d_max = 9; // 새로운 숫자가 알파벳에 매핑 될때마다 --d_max;
map<char,int> a_map; // 각각의 알파벳 A to Z 에 매핑되는 숫자를 저장하는 맵
vector<char> comp_buf; // 각 열 비교시에 2개이상의 알파벳이 있는경우 저장할 자료구조.
vector<char> surr_buf;
int n; // num of strings

void displayMap() {
	for()
}
void method() {
	for(int i=0; i<8; i++) {
		for(int j=0; j<n; j++) {
			if(strings[j][i] != '0') {
				comp_buf.push_back(strings[j][i]);
			}
			if(comp_buf.empty()) continue;
			else if(comp_buf.size() == 1) a_map[strings[j][i]] = d_max--;
			else {
				for(int k=i+1; k<8; ++k) {
					for(int l=0; l<n; ++l) {

						if(find(comp_buf.begin(), comp_buf.end(), strings[l][k]) != comp_buf.end()) {
							surr_buf.push_back(strings[l][k]);
						}
						

					}
					if(!surr_buf.empty()) {
						comp_buf.clear();
						copy(surr_buf.begin(), surr_buf.end(), comp_buf.begin());
						surr_buf.clear();
					} 
					if(comp_buf.size() == 1) {
						a_map[com_buf[0]] = d_max--;
						break;
					}


				}

				for(auto c : comp_buf) {
					a_map[c] = d_max--;
				}

			} 

		}
	}
}


void input() {
	string str("");
	string tmp("");
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> tmp;
		for(int i=0; i<8-tmp.size(); ++i) {
			str.push_back('0');
		}
		str.append(tmp);
		strings.push_back(str);
		str.clear();
		tmp.clear();
	}
	cout << n << endl; 
	for(string s : strings) cout << s << endl;
}


int main() {
	input();
	return 0;
}
