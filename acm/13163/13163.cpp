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
#include <sstream>

using namespace std;

int N;
vector<string> names;
void input(std::istream& pin) {
	pin >> N;
	string tmp_str;
	
	for(int i=0; i<N+1; i++) { 
	   getline(cin, tmp_str);
	   names.emplace_back(tmp_str);
	}
	
	
}

string method(string& name_str) {
	string nam;
	string fin = "god"; 
	stringstream ss(name_str);
	int cnt = 0;
	while(ss >> nam) { 
		if(cnt > 0) fin += nam;
		cnt++;
	}
	return fin;
}

int main() {
	input(cin);
	for(int i=1; i<names.size(); i++) 
		cout << method(names[i]) << endl;
	return 0;
}
