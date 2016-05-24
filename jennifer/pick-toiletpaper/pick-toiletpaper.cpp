#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF   INT_MAX 
#define MAT_MAX 11


struct point
{
	double x;
	double y;
	point(int ax, int ay) : x(ax), y(ay) {}
};

int N; 
double min_val = INF; // 최단경로를 저장할 변수
std::vector<int> min_vec; // 최단경로를 통해 저장될 좌표들의 순서를 저장
std::vector<point> points; // 입력받은 좌표들과 (0,0) , (10,10) 을 저장 , // (0,0) .입력좌표1, 입력좌표2, ... , (10,10) 순//

void swap (int& a, int& b) { 
	int temp;
	temp = a;
	a = b;
	b = temp;
}  


// 두 점사이의 거리를 구하는 함수 
inline double distance_between(point p1, point p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}


// 값을 읽어와 저장합니다.
void input(istream& in) {
	in >> N;
	int x, y;
	
	point p_zero(0,0);
	points.push_back(p_zero);
	
	for(int i=0; i<N; i++) {
		in >> x >> y;
		point p(x,y);
		if(x == 0 && y == 0) continue;
		if(x == 10 && y == 10) continue;
		points.push_back(p);
	}

	
	point p_ten(10,10);
	points.push_back(p_ten);
	
 }

//가능한 모든 permutation을 recursion을 이용하여 찾습니다 
 /*
 ex) v = {1,2,3} i=0, n=2
	123, 132, 213, 231, 312, 313 

이 문제가 모든 가능한 최단경로를 검색해 보아야 한다고 판단, 고정된 출발점과 도착점을 제외한 나머지는 순열 형식으로 열거해 
찾아보았습니다. 
ex) point0, 1, 2, 3, 4
가 있는경우
0 과 4 사이에 1 2 3
0 과 4 사이에 1 3 2
0 과 4 사이에 2 1 3
... 계산 과정 중에 속도를 높이기 위하여 계속 이동 거리를 더해가는 중에 기존의 최소값을 초과 하는경우 더이상 순회하지 않게 pruning 하였습니다.
 */
void permute(std::vector<int> v, int i, int n) { 
	int j; 
	if (i == n) {
		double sum = 0;
		for(int i=0; i<v.size()-1; i++ ) {
			if(sum > min_val) break;
			sum += distance_between(points[v[i]],points[v[i+1]]);
		}

		if(min_val > sum) {
			min_val = sum;
			min_vec.resize(v.size());
			copy(v.begin(), v.end(), min_vec.begin());
		}
	}
	else { 
		for (j = i; j <= n; j++) { 
			swap(v[i], v[j]); 
			permute(v, i+1, n); 
			swap(v[i], v[j]); 
		} 
	} 
} 


int main() {
	input(cin);

	std::vector<int> v;
	for(auto i=0; i<points.size(); i++) 
		v.push_back(i); 

	permute(v, 1, v.size()-2);
	
	cout << min_val << endl;
	for(auto k : min_vec) cout << "(" << points[k].x<<","<<points[k].y<<")" << "->";

	return 0;
}


