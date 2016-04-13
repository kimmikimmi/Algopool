#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int possible_pick;
std::vector<int> possible_nums;
std::vector<int> iterating_space;
int steps;

void input(istream& in) {
	int temp;
	in >> N >> possible_pick;
	for(int i=0; i<N; i++) iterating_space.push_back(i+1);
	for(int i=0; i<possible_pick; i++) {
		in >> temp;
		possible_nums.push_back(temp);
	}
}

void move_to_left(int current, int n_times) {
	steps += n_times;
	if(current != iterating_space.size()-1) current += n_times;
	else 
		current = n_times -1 ;
}

void move_to_right(int current, int n_times) {
	steps += n_times;
	if(current != 0) current -= n_times;
	else 
		current = iterating_space.size() - n_times;
}

void pick_up_begin(int current) {
	if(iterating_space[current] == possible_nums[0]) {
		possible_nums.erase(possible_nums.begin());
		iterating_space.erase(iterating_space.begin() + current);
	} else {
		cout << " it's not begin";
	}
	
}
int dist1(int cur, int poss) {
	return abs(poss - cur);
}
int dist2(int cur, int poss) {
	return abs(cur + (N - poss));
}
void method() {

	int current = 0;
	pick_up_begin(0);
	for(; !possible_nums.empty();) {
		if(possible_nums[0] == iterating_space[current]) {
			;
		} else if(possible_nums[0] > iterating_space[current]) {

			if(dist1(possible_nums[0], iterating_space[current]) < 
				dist2(possible_nums[0], iterating_space[current])) {

				move_to_left(current, dist1(possible_nums[0], iterating_space[current]));

			} else {
				move_to_right(current, dist2(possible_nums[0], iterating_space[current]));
			}

			
		} else {
			if(dist1(possible_nums[0], iterating_space[current]) < 
				dist2(possible_nums[0], iterating_space[current])) {

				move_to_right(current, dist1(possible_nums[0], iterating_space[current]));
			
			} else {
				move_to_left(current, dist2(possible_nums[0], iterating_space[current]));
			}
		}
		pick_up_begin(current);
	}

}

int main() {
	input(cin);
	method();
	cout << steps;
	return 0;
}
