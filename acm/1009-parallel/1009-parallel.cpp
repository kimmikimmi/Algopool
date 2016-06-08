#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;


int test_cases;
vector<int> a_set;
vector<int> b_set;

void input(istream& in) {
	in >> test_cases;
	int a,b;
	for(int i=0; i<test_cases; i++) {
		in >> a >> b;
		a_set.push_back(a);
		b_set.push_back(b);
	}
}

int method(int a, int b) {
	int ans = 1;
	for(int i=0; i<b; i++) {
		ans *= a;
		ans %= 10;
	}
	return ans;
}

int main() {
	input(cin);
	for(int i=0; i<test_cases; i++) 
		cout << method(a_set[i], b_set[i]) << endl;
	return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
 
// typedef struct input{
//     int a;
//     int b;
// } INPUT;
 
// int list[10][4] ={{},{1}, {6, 2, 4, 8}, {1, 3, 9, 7},{6,4},{5},{6}, {1, 7, 9, 3}, {6, 8, 4, 2},{1,9} };
 
 
// int main()
// {   
//     int row;
//     INPUT* arr;
//     int i;
//     int a,b;
//     int mod;
//     int* answer;
 
//     scanf("%d", &row);
//     arr = (INPUT*) malloc (sizeof(INPUT)*row);
//     answer = (int*) malloc (sizeof(int)*row);   
//     for(i=0;i<row;i++)
//     {
//         scanf("%d %d",&arr[i].a, &arr[i].b);
//     }
 
//     for(i=0;i<row;i++)
//     {
//         a = arr[i].a%10;
//         b = arr[i].b;
         
//         if( a == 1 || a==5 || a==6)
//         {
//             answer[i]=a;
//         }
//         else if( a ==2 || a==3 || a==7 || a==8)
//         {
//             mod = b%4;
//             answer[i] = list[a][mod];
//         }
//         else if(a == 4 || a == 9)
//         {
//             mod = b%2;
//             answer[i] = list[a][mod];
//         }
 
//         else if( a==0)
//         {
//             answer[i] =10;
//         }
     
//     }
//     for(i=0;i<row;i++)
//     {
//         printf("%d\n", answer[i]);
//     }
// }