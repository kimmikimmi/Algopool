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

struct pixel {
	int R;
	int G;
	int B;
};

int N;

vector<pixel> pixels;
vector<int> cache;
vector<pixel> min_costs;

void input(std::istream& pin) {
	pin >> N;
	
	pixel p;
	pixels.assign(N, p);
	min_costs.assign(N, p);

	cache.assign(N,-1);
	
	for(int i=0; i<N; i++) 
		pin >> pixels[i].R >> pixels[i].G >> pixels[i].B;

	min_costs[0].R = pixels[0].R;
	min_costs[0].G = pixels[0].G;
	min_costs[0].B = pixels[0].B;

}

int method(int x) {
	if(x == 0) return min({min_costs[0].R, min_costs[0].G, min_costs[0].B});
	
	min_costs[x].R = pixels[x].R + min({min_costs[x-1].G, min_costs[x-1].B});
	min_costs[x].G = pixels[x].G + min({min_costs[x-1].R, min_costs[x-1].B});
	min_costs[x].B = pixels[x].B + min({min_costs[x-1].R, min_costs[x-1].G});
	return min({min_costs[x].R, min_costs[x].G, min_costs[x].B}); 
}

int main() {
	input(cin);
	for(int i=0; i<N-1; i++) 
		 method(i);
	cout << method(N-1) << endl;
	return 0;
}
