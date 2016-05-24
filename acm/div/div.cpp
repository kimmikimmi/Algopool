#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;
long long int N;
int F;
std::vector<long long int> v;

void input(istream& in) {
	in >> N >> F;
}

void int_to_char_arr(int a) {
	if(a < 10) cout << "0" << a << std::endl;

	else cout << a << endl;
}

void method() {

	int digit = 0;
	int tmp = N;
	int ans = 0;

	for(long long int i=1; i<N; i*=10) {
		digit++;
	}
	// cout << "digit = " << digit << endl;
	
	for(int i=digit; i>1; i--) {
		int k = tmp - (tmp % (int)pow(10, i));
		v.push_back(k);
		tmp -= k;
		
	}
	
	for(int i=0; i<v.size(); i++) {
		// cout << v[i] << endl;
		v[i] = v[i] % F;
		ans += v[i];	
		// cout << v[i] << endl;
	} 

	for(int i=0; ; i++) {
		if((i + ans) % F == 0) {
			int_to_char_arr(i);
			break;
		}
	}
}

int main() {
	input(cin);
	
	method();
 	return 0;
}
