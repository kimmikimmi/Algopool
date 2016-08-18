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

#define KING 1
#define QUEEN 1
#define KNIGHT 2
#define BISHOP 2
#define ROOK 2
#define PAWN 8

int king, queen, knight, bishop, rook, pawn;
void input(std::istream& pin) {
	pin >> king >> queen >> rook >> bishop >> knight >> pawn;
}

int method() {
	
	return 0;
}

int main() {
	input(cin);
	cout << KING - king << " " << QUEEN - queen << " " << ROOK - rook << " " << BISHOP - bishop << " " << 
		  	KNIGHT - knight << " " <<  PAWN - pawn << endl;	
	return 0;
}
