#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <tuple>
#include <set>

using namespace std;
int N;
int len;
string io_str;

void input(std::istream& pin) {
	pin >> N;
	pin >> len;
	pin >> io_str;
}

vector<int> KMP(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
	vector<int> matches;

        if(K.size() == 0)
        {
            matches.push_back(0);
            return matches;
        }
	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;
	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) matches.push_back(sp - K.size());
	}
	
	return matches;
}

string P(int num) {
	string ret_str = "I";
	string OI = "OI";
	
	for(int i=0; i<num; i++) 
		ret_str += OI;

	return ret_str;
}

int main() {
	input(cin);

	cout << KMP(io_str, P(N)).size() << endl;

	return 0;
}
