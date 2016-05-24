// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <list>
// #include <map>
// #include <cmath>

// using namespace std;

// int n;
// std::vector<string> string_bag;

// void input(istream& in) {
// 	in >> n;
// 	string tmp_str;

// 	for (int i = 0; i < n; ++i)
// 	{	
// 		in >> tmp_str;
// 		string_bag.push_back(tmp_str);
// 	}
// }

// string method() {
	
// 	string res = "";
// 	int str_length = string_bag[0].size();

// 	for (int i = 0; i < str_length; ++i)
// 	{
// 		for(int j=1; j<n; j++) 
// 		{
// 			if(string_bag[0][i] != string_bag[j][i]) {
// 				res += '?';
// 				break;
// 			} else {
// 				if( j == n-1) {
// 					res += string_bag[0][i];
// 				}
// 			}
// 		}
// 	}

// 	return res;
// }

// int main() {
// 	input(cin);
// 	cout << method();
	
// 	return 0;
// }
#include <stdio.h>
 
int main(void){
 
    // freopen("input.txt", "r", stdin);
 
    char filename[55][55]={0,};
    int n, i, j, answer=0;
 
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", filename[i]);
    }
 
    for(i=0; filename[0][i]!=0; i++){
        int isdiff=0;
        char tempchar = filename[0][i];
        for(j=1; j<n; j++){
            if(filename[j][i]!=tempchar){
                isdiff=1;
                break;
            }
        }
        if(isdiff==1){
            printf("?");
        }
        else printf("%c", tempchar);
    }
 
    return 0;
}