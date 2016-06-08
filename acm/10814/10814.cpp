#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int N;
vector<pair<int, string>> client_list; 

void input(istream& in) {
	in >> N;
	string name;
	int age;

	for(int i=0; i<N; i++) {
		in >> age >> name;
		pair<int, string> p(age, name);
		client_list.push_back(p);
	}
}

void method() {
	sort(client_list.begin(), client_list.end(), [](pair<int, string> p1,
				pair<int, string> p2) { return p1.first < p2.first; });
}

int main() {
	input(cin);
	method();
	for(auto& client : client_list) 
		cout << client.first << " " << client.second << "\n";

	return 0;
}
