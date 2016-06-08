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

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	int T;
	int N;
	string S;
	int L;
	vector<pair<string, int>> drink_consuming_vec;
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> N;
		for(int j=0; j<N; j++) {
			cin >> S >> L;
			pair<string, int> p(S,L);
			drink_consuming_vec.push_back(p);
		}
		
		sort(drink_consuming_vec.begin(), drink_consuming_vec.end(), [](pair<string, int> p1, pair<string, int> p2) {
				return p1.second > p2.second;});
		cout << drink_consuming_vec[0].first << endl;
	}
	return 0;
}
