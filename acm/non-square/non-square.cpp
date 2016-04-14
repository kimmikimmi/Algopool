#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <string>
#include <sstream>

using namespace std;


// long long int low_bound;
// long long int up_bound;
// long long int fringe[1000001];

// void input(istream& in) {
	
// 	in >> low_bound >> up_bound;
	
// 	for(int i=low_bound; i<=up_bound; i++) {
// 		fringe.push_back(i);
// 	}
	
// }
// // 두 수 사이의 제곱수가 아닌수의 개수를 출력하는 함수.
// long long int method() {
// 	long long int small_square = sqrt(low_bound);// cout << small_square << endl;
// 	long long int big_square = sqrt(up_bound);// cout << big_square << endl;
// 	long long int min;
// 	long long int max = big_square;
	
// 	if(small_square * small_square  < low_bound) {
// 		min =  floor(small_square) + 1;
// 	} else {
// 		min = small_square;
// 	}

// 	long long int out = max - min + 1;// cout << out << endl;
// 	return up_bound - low_bound + 1 - out;

// }

// int main() {
// 	input(cin);
// 	 cout << method();

// 	return 0;
// }


 
using namespace std;
 
bool check[5000001]; // min + i가 제곱수인지 아닌지
 
int main()
{
    vector<long long int> zegop;
     
    long long int min, max;
    cin >> min >> max;
    for (long long int i = 2;; i++)
    {
        if (i*i > max) break;
        zegop.push_back(i*i);
    }

    long long int answer = 0;
    int size = zegop.size();
    
    for (int i = 0; i < size; i++)
    {
        for (long long int j = (min / zegop[i])*zegop[i]  ;j<=max; j += zegop[i])
        {
            if (j - min < 0) continue;
            if (check[j - min] == 0)
            {
                check[j - min] = 1;
                answer++;
            }
        }
    }
    cout << max-min-answer+1;
    return 0;
}