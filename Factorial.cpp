#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//int *cache;
std::vector<int> a;

void input() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
		a.push_back(i+1);
	
}

void swap(int &a, int &b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void print(int k) {
	sort(a.begin(), a.end());
	for(int i=0; i<k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

/* 
@param : 
	depth :
	n : 배열의 크기
	k : 몇개를 뽑아서 순열을 만들 것인가?
*/
void permute( int depth, int n, int k) { 
	
	if (depth == k) print(n);
	else { 
		for (int i = depth; i<n; i++) { 
			swap(a[i], a[depth]); 
			permute(depth+1, n, k); 
			swap(a[i], a[depth]); //backtrack
		}

	}
}


int main(int argc, char const *argv[])
{
	/* code */
		
		int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
		a.push_back(i+1);
		permute(0,a.size(),a.size());
	
	

	return 0;
}
