#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define STONE -1
#define DEN -2
#define START -3
#define WATER -4
#define DEFAULT 0;


struct Cell {

	int status;
	int red;
	int blue;
	bool red_visited;
	bool blue_visited;

	Cell(int ar, int ab) : red(ar), blue(ab) {}
	Cell() = default;
	Cell(int s) : status(s) {};

};

struct Point
{
	int x;
	int y;
	
	Point(int ax, int ay) : x(ax), y(ay) {}
};


int** forest;
Cell** exp_forest;
int m;
int n;

void input(istream& lin) {
	
	char read_buf;
	lin >> m >> n;
	forest = new int*[m];
	for(int i=0; i<m; i++)
		forest[i] = new int[n];
	

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {

			lin >> read_buf;
			switch(read_buf) {
				case '.':
					forest[i][j] = DEFAULT;
					break;
				case 'X':
					forest[i][j] = STONE;
					break;
				case 'S':
					forest[i][j] = START;
					break;
				case 'D':
					forest[i][j] = DEN;
					break;	
				case '*':
					forest[i][j] = WATER;
					break;
				default :
					cout << "unknown charactor " << read_buf << " came in" << endl;
			}
		}
	}
}

void mk_exp_forest() {
	exp_forest = new Cell*[m+2];
	for(int i=0; i<m+2; i++)
		exp_forest[i] = new Cell[n+2];

	for(int i=0; i<m+2; i++) {
		for(int j=0; j<n+2; j++) {
			exp_forest[i][j].red = 0; exp_forest[i][j].blue = 0; exp_forest[i][j].red_visited = false; exp_forest[i][j].blue_visited = false;

			if(i==0 || j==0 || i==m+1 || j==n+1) {
				exp_forest[i][j].status = STONE;
			} else {
				exp_forest[i][j].status = forest[i-1][j-1];
			}
		}
	}
}


bool is_possible_to_step(int x, int y) {
	if(exp_forest[x][y].status == 0 && exp_forest[x][y].red_visited == false ) return true;

	return false;
}



void make_steps(int sr, int sc, int dr, int dc) {
	exp_forest[sr][sc].red = 0;
	std::vector<Point> point_q;
	int x, y;
	int visited = -1;
	int step = 1;
	Point p(sr,sc);
	exp_forest[sr][sc].red_visited = true;
	point_q.push_back(p);


	while(!point_q.empty() && exp_forest[dr][dc].red == 0) {
		
		x = point_q.front().x;
		y = point_q.front().y;
		
		if(is_possible_to_step(x-1, y)) {
			exp_forest[x-1][y].red = step;
			exp_forest[x-1][y].red_visited = true;
			p.x = x-1; p.y = y;
			point_q.push_back(p);
		} else {

		} 
		if(is_possible_to_step(x+1, y)) {
			exp_forest[x+1][y].red = step;
			exp_forest[x+1][y].red_visited = true;
			p.x = x+1; p.y = y;
			point_q.push_back(p);
		} else {

		}
		if(is_possible_to_step(x, y+1)) {
			exp_forest[x][y+1].red = step;
			exp_forest[x][y+1].red_visited = true;
			p.x = x; p.y = y+1;
			point_q.push_back(p);
		} else {

		}

		if(is_possible_to_step(x, y-1)) {
			exp_forest[x][y-1].red = step;
			exp_forest[x][y-1].red_visited = true;
			p.x = x; p.y = y-1;
			point_q.push_back(p);
		} else {

		}	
		step++;
		point_q.erase(point_q.begin());
		
	}
}

inline void display() {
	for(int i=0; i<m+2; i++) {
		for(int j=0; j<n+2; j++) {
			cout << exp_forest[i][j].red << "\t" ;
		}
		cout << endl;
	}
	
}

inline void display2() {
	for(int i=1; i<m+1; i++) {
		for(int j=1; j<n+1; j++) {
			cout << exp_forest[i][j].status << "\t" ;
		}
		cout << endl;
	}
	
}
void method() {
}

int main() {
	input(cin); 
	mk_exp_forest();
	make_steps(3,2, 1,1);
	display();
	display2();
	return 0;
}
