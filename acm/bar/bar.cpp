#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
//Assume 32 bit decimal number
string DecimalToBinaryString(int a)
{	

    string binary = "";
    int mask = 1;
    for(int i = 0; i < 31; i++)
    {
        if((mask&a) >= 1) {
            binary = "1"+binary;
        	cnt++;
        }
        else
            binary = "0"+binary;
        	mask<<=1;
    }
    
    return binary;
}

void method() {
}

int main() {
	int n;
	cin >> n; 
	string str =  DecimalToBinaryString(n);
	cout << cnt;
	return 0;
}
