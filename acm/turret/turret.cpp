#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cases;
struct Point{
	int x;
	int y;
	int r;
};
std::vector<Point> pointA;
std::vector<Point> pointB;

	


void input() {
	Point temp_point;
	cin >> cases;
	for(int i=0; i<cases; i++) {
		cin >> temp_point.x >> temp_point.y >> temp_point.r ;
		pointA.push_back(temp_point);
		
		cin >> temp_point.x >> temp_point.y >> temp_point.r ;
		pointB.push_back(temp_point);
	}
}

int method(int i) {
	
	auto point1 = pointA[i]; auto point2 = pointB[i];
	
	auto distance = [](Point p1, Point p2) {
	return pow((p1.x - p2.x),2) + pow(p1.y - p2.y,2);
	};

	auto is_same_spot = [](Point p1, Point p2) {
	return (p1.x == p2.x) && (p1.y == p2.y) ;
	};

	int dist = distance(point1, point2); 
	int rad1 = pow(point1.r + point2.r, 2); 
	int rad2 = pow(point1.r - point2.r, 2); 

	if(is_same_spot(point1, point2) && (point1.r == point2.r)) return -1;
	if(rad1 == dist || rad2 == dist)  return 1;
	if(is_same_spot(point1, point2) || dist > rad1 || dist < rad2) {
		return 0;
	} else if(dist < rad1 || dist > rad2) {
		return 2;
	} 

	return 0;

}

int main() {
	input();
	// for_each(pointB.begin(), pointB.end(), [](Point& p) {cout << p.x << endl;});
	for(int i=0; i<cases; i++) {
		cout << method(i) << endl;
	}
	return 0;
}
