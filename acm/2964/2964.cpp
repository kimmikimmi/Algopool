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
#define pii pair<int, int>

int N;
vector<pii> pins_x_order;
vector<pii> pins_y_order;

string inst;

void input(std::istream& pin) {
	pin >> N;
	int x,y;
	pins_x_order.resize(N);
	pins_y_order.resize(N);

	for(int i=0; i<N; i++) {
		scanf("%d %d", &x, &y);
		pins_x_order[i] = make_pair(x,y);
		pins_y_order[i] = make_pair(x,y);
	}

	pin >> inst;
}

double getS(pii w, pii n, pii e, pii s) {
	double ans =  abs(w.first - e.first) * abs(n.second - s.second); 
	cout << "큰 정사각형 = " << ans <<endl;
	double dif = 0.5 * abs(w.first - n.first) * abs(w.second - n.second);
	dif += 0.5 * abs(w.first - s.first) * abs(w.second - s.second);
	dif += 0.5 * abs(e.first - n.first) * abs(e.second - n.second);
	dif += 0.5 * abs(e.first - s.first) * abs(e.second - s.second);
	ans -= dif;
	return ans;
}

int method(char& comm, int len) {
	
	switch(comm) {
	
		case 'L':
			pins_y_order.erase(find(pins_y_order.begin(), pins_y_order.end(), pins_x_order[0]));
			pins_x_order.erase(pins_x_order.begin());
			break;
		case 'R':
			pins_y_order.erase(find(pins_y_order.begin(), pins_y_order.end(), pins_x_order[len-1]));
			pins_x_order.erase(pins_x_order.end()-1);
			break;
		case 'U':
//			cout << pins_y_order[len-1].first << "," << pins_y_order[len-1].second << "size = " << 
//			   	pins_y_order.size() << endl;
			
			pins_x_order.erase(find(pins_x_order.begin(), pins_x_order.end(), pins_y_order[len-1]));
			pins_y_order.erase(pins_y_order.end()-1);

//			cout << pins_y_order.size() << endl;
//			cout << pins_y_order[pins_y_order.size()-1].first << "," << pins_y_order[len-2].second << endl;
			break;
		case 'D':
			pins_x_order.erase(find(pins_x_order.begin(), pins_x_order.end(), pins_y_order[0]));
			pins_y_order.erase(pins_y_order.begin());
	}

	return 0;
}

int main() {
	input(cin);
	
	cout << inst << endl;
	sort(pins_x_order.begin(), pins_x_order.end());
	sort(pins_y_order.begin(), pins_y_order.end(), [](pii p1, pii p2) {
			return p1.second < p2.second;});
	
	for(int i=0; i<N; i++) 
		cout << pins_x_order[i].first << "," << pins_x_order[i].second << " !!!" <<  
		   pins_y_order[i].first << "," << pins_y_order[i].second << endl;

	int inst_len = inst.size();
	int i=0;
	for(auto& it : inst) {
		//if(i == N-2) break;
		int tmp_len = N-i;
		cout << " 4 점 " << pins_x_order[0].first << "," << pins_x_order[0].second << endl;
		cout << " 4 점 " << pins_y_order[tmp_len-1].first << "," << pins_y_order[tmp_len-1].second << endl;
		cout << " 4 점 " << pins_x_order[tmp_len-1].first << "," << pins_x_order[tmp_len-1].second << endl;
		cout << " 4 점 " << pins_y_order[0].first << "," << pins_y_order[0].second << endl;
		cout << getS(pins_x_order[0], pins_y_order[tmp_len-1], pins_x_order[tmp_len-1], pins_y_order[0]) << endl;
		method(it, tmp_len);
		i++;
	}
	return 0;
}
