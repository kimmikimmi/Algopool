#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

int n;
std::vector<int> grapes;
vector<int> grape_sol;
void input(istream& in) {
	in >> n;
	int temp;
	for(int i=0; i<n; i++) {
		in >> temp;
		grapes.push_back(temp);
		grape_sol.push_back(-1);
	}
	grape_sol[0] = grapes[0];
	grape_sol[1] = grapes[0] + grapes[1];
	grape_sol[2] = max({ grape_sol[1], (grapes[1] + grapes[2]), (grapes[0] + grapes[2])});
	
}

int method(int i) {
	if(grape_sol[i] != -1) return grape_sol[i];

	if(i == 0) {
		return grape_sol[0];
	} else if(i == 1) {	
		return grape_sol[1];
	} else if(i == 2) {
		return grape_sol[2];
	} else if(i == 3) {
		return grape_sol[3] = max({ (grapes[3] + grapes[2] + method(0)) , 
				 			(grapes[3] + max(method(1), method(0))),
							method(2) });
	}
	
	return grape_sol[i] = max({ (grapes[i] + grapes[i-1] + max(method(i-3), method(i-4))) , 
				 			(grapes[i] + max(method(i-2), method(i-3))),
							method(i-1) });
}

int main() {
	input(cin);
	
	//for(auto k : grapes) cout << k << endl;
	cout << method(n-1) << endl;
	  // for(int i=0; i<grape_sol.size(); i++) cout << i << " = " << grape_sol[i] << endl;
	return 0;
}
