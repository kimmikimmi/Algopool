#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
std::vector<int> players;
std::vector<int> current_cards_p;
std::vector<int> current_cards;
std::vector<int> S;


void input(istream& in) {
	in >> n;
	int temp;
	for(int i=0; i<n; i++) {
		in >> temp;
		players.push_back(temp);

	}
	for(int i=0; i<n; i++) {
		in >> temp;
		S.push_back(temp);
	}

}


int method() {
	
	int cnt = 0;

	vector<int> target(n); 
	for(int i=0; i<n; i++) target[i] = i%3;

	if(target == players) return 0;

	for(int i=0; i<n; i++)
		if(S[i] == i && players[i] != i%3) return -1;
	
	current_cards.resize(n);
	copy(players.begin(), players.end(), current_cards.begin());

	 current_cards_p.resize(n);
	copy(players.begin(), players.end(), current_cards_p.begin());
	

	std::vector<int> tmp(n);
	// for(auto k : current_cards) cout << k <<" ";
	// 		cout << endl;
	while(true) {

		cnt++;
		
		for(int i=0; i<n; i++) {
			tmp[S[i]] = current_cards[i];
		}
		copy(tmp.begin(), tmp.end(), current_cards.begin());
		
		// for(auto k : current_cards) cout << k <<" ";
		// 	cout << endl;
		
		 if(target == current_cards) return cnt;
		 else if(current_cards_p == current_cards) return -1;

		 
	}

	return 0;
	
}

int main() {
	input(cin);
	
	cout << method();
	return 0;
}
