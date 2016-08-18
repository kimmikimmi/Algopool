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

using namespace std;

vector<string> strings;

void input(std::istream& pin) {
	string tmp;

	while(getline(pin, tmp)) {
		strings.push_back(tmp);
	}

}

int method() {
	return 0;
}

int main() {
	input(cin);
	
	for(auto& it : strings) {
		int small = 0;
		int capital = 0;
		int number = 0;
		int newLine = 0;
		for(int i=0; i<it.size(); i++) {
			if(it[i] >= '0' && it[i] <='9') number++;
			else if(it[i] >= 'a' && it[i] <= 'z') small++;
			else if(it[i] >= 'A' && it[i] <= 'Z') capital++;
			else 
				newLine++;
		}
		cout << small << " " << capital << " " << number << " " << newLine << endl;
	}	
		
	return 0;
}
