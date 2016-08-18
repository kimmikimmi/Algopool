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

int T;

void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> T;
	int n;
	for(int i=0; i<T; i++) {
		cin >> n;
		vector<int> seq_vec;
		vector<bool> bit_map(n+1,false);
		vector<int> ans_vec(n+1,-1);
		
		int tmp;
		for(int j=0; j<n; j++) {
			cin >> tmp;
			seq_vec.push_back(tmp);
		}
		bool flag = false;	
		for(int j=n-1; j>=0; --j) {
			flag = false;
			if(seq_vec[j] > j) {
				flag = true;
				cout << "IMPOSSIBLE" << endl;
				break;
			} else {
				int cnt = 1;
				for(int k=1; k<n+1; k++) {
					if(cnt <= seq_vec[j]) {
						if(!bit_map[k]) {	
							cnt++;
							//cout << "cnt = " << cnt << endl;
						} else 
							continue;
					} 	
					else  {
					   if(!bit_map[k]) {	
							bit_map[k] = true;
							ans_vec[j+1] = k;
							break;
					   } else 
						   continue;
						//cout << "ans_vec[" << k << "] = " << ans_vec[k] << endl;
					}
				}
			}	
		}
		if(!flag) {
			for(int i=1; i<n+1; i++) cout << ans_vec[i] << " ";
			cout << endl;
		}
	}
	return 0;
}
