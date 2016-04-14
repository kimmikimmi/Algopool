#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;



struct planet
{
	int x;
	int y;
	int r;
	planet() : x(0), y(0), r(0) {}
	planet(int cx, int cy, int cr) : x(cx), y(cy), r(cr) {}
};

struct point
{
	int x;
	int y;
	point() : x(0), y(0) {}
	point(int x1, int y1) : x(x1), y(y1) {}
};

vector<vector<planet>> planets;

int test_cases;
std::vector<point> starts;
std::vector<point> endss;

void input(istream& in) {
	
	
	in >> test_cases;
	planets.resize(test_cases);

	int x1, x2, y1, y2;
	int px, py, pr;
	int num_planets;

	for(int i=0; i<test_cases; i++) {
		
		in >> x1 >> y1 >> x2 >> y2;
		
		point p1(x1, y1);
		point p2(x2, y2);

		starts.push_back(p1);
		endss.push_back(p2);

		
		in >> num_planets;

		for(int j=0; j<num_planets; j++) {
			in >> px >> py >> pr;
			planet pl(px, py, pr);
			planets[i].push_back(pl);
		}
	}

}

inline int square_dist(int x1, int y1, int x2, int y2) {
	return (x1-x2)*(x1-x2) + (y2-y1)*(y2-y1);
}

bool includes_point(planet pl, point p) {
	if(square_dist(pl.x, pl.y, p.x, p.y) > pl.r*pl.r) return false;

	return true;
}

int method(int testcase) {
	int num_boundary = 0;
	for(int i=0; i<planets[testcase].size(); i++) {
		if(includes_point(planets[testcase][i], starts[testcase]) 
			&& includes_point(planets[testcase][i], endss[testcase])) {
			;
		} else {
			if(includes_point(planets[testcase][i], starts[testcase])) {
				num_boundary++;
			} else if(includes_point(planets[testcase][i], endss[testcase])) {
				num_boundary++;
			}
		}
	
	}
	

	return num_boundary;
}

int main() {
	input(cin);
	for(int i=0; i<test_cases; i++) 
		cout << method(i)<< endl;
	return 0;
}
