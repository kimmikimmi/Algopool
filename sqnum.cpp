#include <iostream>
#include <math.h> // ctrl + command : 줄바꿈.
#include <algorithm>
#include <vector>
#include <list>



using namespace std;
list<int> a;
vector<int> possible;

int minNum;
void methodSub(int n);
void methodSub2(int n);
int depth;

int method(int n) {
	// 입력을 이용해 재귀함수를 호출한다.
	// possible 에 n 이하의 완전제곱수들을 possible 벡터에 넣는다
	int maxSqrt = (int)sqrt(n);
	possible.clear();
	// print(maxSqrt);
	for(int i=0; i<maxSqrt; i++) {
		possible.push_back(maxSqrt - i);
		// cout << possible[i] << endl;
	}

	methodSub2(n);
	// 답을 리턴한다.
	return minNum;

}

void methodSub(int n) {
	++depth;
	
	// mySleep(1);
	if(n == 0) {
		if(minNum == 0) minNum = depth;
		if(minNum > depth) {
			minNum = depth;
		}
		// printf("depth %d at n=0\n", depth);
		
		
		depth--;
		return ;
	} else {
		for(int i = 0; i < possible.size(); ++i) {
			int square = (int)pow(possible[i],2);

			if(n < square) continue;

			//candidatePath.push_back(possible[i]);
			
			methodSub(n-square);
		}
		 
		--depth;
		return;
	}
	
}

int temp;
void methodSub2(int n) {
	++depth;
	// cout << "depth++" << " ";
	 if(minNum != 0 && minNum <= depth) return;
	if(temp != 0 && temp <= depth) return;
	if(n == 0) {
		
		if(minNum == 0) minNum = depth;

		if(minNum > depth) {
			minNum = depth;
		}

		 // printf(" So depth %d at n=0\n", depth);
		
		// cout << "depth--" << " ";
		depth--;
		return ;
	} else {
		for(int i = 0; i < possible.size(); ++i) {
			

			int square = (int)pow(possible[i],2);

			if(n < square) continue;
			//sadsdasdsadasdasdasdasdsadsadasdsadsadsadasdasdsadsadsad
			if(possible[i] == 1) {
				depth += (n);
				// cout << "depth = depth +" << (n) << " " ;
				
				if(minNum == 0) minNum = depth;

				if(minNum > depth) {
					minNum = depth;
				}

				 // printf(" So depth %d at n=0\n", depth);
				
				// cout << "depth = depth -" << n+1 << " ";
				depth -= (n+1);
				temp = depth -1;
				return;
				
			//asdasdasdasdasdasdsadasdasdasdasdsadasdasdasdasdasdasdasd
			} else {
				methodSub2(n-square);
			}		
			
		}
		 
		--depth;
		cout << "depth--" << " ";
		return;
	}
	
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	
		method(N);
		cout << minNum -1  ;
	
	return 0;
}
