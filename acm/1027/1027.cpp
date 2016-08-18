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
int N;
vector<pair<int, long long>> buildings;

void input(std::istream& pin) {
	
	pin >> N;
	long long tmp;
	for(int i=0; i<N; i++) {
		pin >> tmp;
		pair<int, long long> p(i, tmp);
		buildings.push_back(p);	
	}
}

int ccw( pair<int, long long> p1, pair<int, long long> p2, pair<int, long long> p3) {
	long long expression = (p2.second - p1.second) * (p3.first - p1.first);
    expression = expression	- (p3.second - p1.second)*(p2.first - p1.first); 
	if(expression > 0) return 1; // cw
	else if( expression == 0) return 0; // in the line
	else // ccw
		return -1;
}	


int method(int nth) {
	
	int right_cnt = 1; // itself;
	int left_cnt = 1;
	
	int mid_index = nth+1;
	
	for(int i=nth+2; i<N; i++) {	

		if(ccw(buildings[nth], buildings[mid_index], buildings[i]) == -1) {
			cout <<"Toward right side" << buildings[nth].first << "," << buildings[nth].second << "\t" 
				<< buildings[mid_index].first << "," << buildings[mid_index].second << "\t" 
				<< buildings[i].first << "," << buildings[i].second << endl;

			right_cnt++;
			mid_index = i;
		} 
	}

	 mid_index = nth-1;
	for(int i=nth-2; i>=0; i--) {
		if(ccw(buildings[i], buildings[mid_index], buildings[nth]) == -1) {
			cout <<"Toward left side " << buildings[nth].first << "," << buildings[nth].second << "\t" 
				<< buildings[mid_index].first << "," << buildings[mid_index].second << "\t" 
				<< buildings[i].first << "," << buildings[i].second << endl;

			left_cnt++;
			mid_index = i;
		}
	}
	if(nth == N-1) right_cnt--;
	if(nth == 0) left_cnt--;	
	cout << nth << "번째 오른쪽 : " << right_cnt << ", 왼쪽 : " << left_cnt << endl;
	return  right_cnt + left_cnt ;	
}

int main() {
	input(cin);
	int max_height = 0;
	for(int i=0; i<N; i++) {
		int tmp = method(i);
		if( tmp > max_height) max_height = tmp;
	}
	cout << max_height << endl;
	return 0;
}
