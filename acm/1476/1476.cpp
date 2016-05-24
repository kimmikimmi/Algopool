#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;


int E; // 1 <= E <= 15
int S; // 1 <= S <= 28
int M; // 1 <= M <= 19

void input(istream& in) {
	in >> E >> S >> M;
	
}

int method() {
	if((E== 15) && (S == 28) && (M == 19)) {
		
		return 7980;
	}

	else if(E==15 && S == 28) {
		
		for(int i=420;; i= i+420) {
			if( i%19 == M) {
				return i;
			}
		}
	}

	else if(E==15 && M == 19) {
		
		for(int i=285;; i= i+285) {
			if( i%28 == S) {
				return i;
			}
		}
	}

	else if(S==28 && M == 19) {
		
		for(int i=532;; i= i+532) {
			if( i%15 == E) {
				return i;
			}
		}
	}

	else if(E == 15) {
		
		for(int i=15;; i= i+15) {
			if( i%28 == S && i%19 == M) {
				return i;
			}
		}
	}

	else if(S == 28) {
		
		for(int i=28;; i= i+28) {
			if( i%15 == E && i%19 == M) {
				return i;
			}
		}
	}

	else if(M == 19) {
		
		for(int i=19;; i= i+19) {
			if( i%28 == S && i%15 == E) {
				return i;
			}
		}
	}
	else {
		
		for(int i=1;; i++) {
			if(i%15==E && i%28 == S && i%19 == M) {
				return i;
			}
		}
	
	}
    
		
}

int main() {
	input(cin);
	cout << method() << endl;


	
	return 0;

}
