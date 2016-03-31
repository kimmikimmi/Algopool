#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int width;
int *cache;
int method_sub(int i);

void method() {

	cin >> width;
	cache = new int[width+1];

	for(auto i=0; i<width+1; i++) {
		cache[i] = -1; 
	}

	cout << method_sub(width)%10007; 
}

int method_sub(int i) {
	if(cache[i] != -1) return cache[i];

	if(i < 3) {
		cache[i] = i;
	 	return cache[i];
	 }
	
	cache[i] = (method_sub(i-2)%10007) + (method_sub(i-1)%10007);
	return cache[i];

}

 
int main() {
	method();
		
	return 0;
}
