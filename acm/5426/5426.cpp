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

int T;
vector<string> encrypted_msg;

void input(std::istream& pin) {
	pin >> T;
	encrypted_msg.assign(T, "");
	for(int i=0; i<T; i++)
		pin >> encrypted_msg[i];
}

void decrypt(string& enc_msg) {
	int len = enc_msg.size();
	int mat_size = sqrt(len);
	vector<vector<char>> dec_mat(mat_size+1, vector<char>(mat_size+1));
	
	for(int i=0; i<mat_size; i++) 
		for(int j=0; j<mat_size; j++) 
			dec_mat[i][j] = enc_msg[i*(mat_size) + j];	
	
	//for(int i=0; i<mat_size; i++) {
	//	for(int j=0; j<mat_size; j++)  
	//		cout << dec_mat[i][j] << " ";
	//cout << endl;
	//}
	//cout << endl;
	for(int i=0; i<mat_size; i++) {
		for(int j=0; j<mat_size; j++)  
			cout << dec_mat[j][mat_size-1-i];
	}
	cout << endl;
}

int main() {
	input(cin);
	for(auto& it : encrypted_msg)
		decrypt(it);	

	return 0;
}
