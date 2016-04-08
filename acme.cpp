#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <algorithm>

int* arr;
int n; //target , input
int size  =0;
void pushAllElements(int n) {
	
	for(int i=0;; i++) {
		if((int)pow((double)i+1, 2.0) <= n){
			arr[i] = (int)pow((double)(i+1), 2.0);
			size++;
		} else {
			break;
		}
	}
	
}
int min  = 1;

void getSquare(int k, std::vector<int> v) {
	int temp = 0;

	for(auto iter = v.end(); iter!=v.begin(); --iter) {
		if(k % *(iter-1) == 0) {
			temp += (int) (k / (*iter));
			cout << "temp = " << temp << endl;
			temp = 0;
			break;
		} else {
			temp += (int)(k / (*iter));
			getSquare((int)(k % *(iter-1)), v);
		}

		

	}
	

}

int main(int argc, char const *argv[])
{
	
	cin >> n;
	arr = new int[n];
	pushAllElements( n);
	vector<int> squares(arr, arr+size);
	for(auto iter = squares.begin(); iter!= squares.end() ;iter++) {
		cout << *iter << " ";
	} cout <<"Asdasdasd" <<endl;
	getSquare(n, squares);

	return 0;
}
