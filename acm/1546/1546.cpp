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
float N;
vector<float> scores;

void input(std::istream& pin) {
	pin >> N;
	float tmp;
	for(int i=0; i<N; i++) {
		pin >> tmp;
		scores.push_back(tmp);
	}
}

float get_avg() {
	sort(scores.begin(), scores.end());
	float max_score = scores[scores.size()-1];
	int sum = 0;
	for(auto& it : scores) sum += it;
	printf("%.2f", sum/max_score*100/N);	
	return 0;
}

int main() {
	input(cin);
	get_avg();
	return 0;
}
