#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

string N;
string buf;

void input(istream& in) {
	in >> N;
}

void method() {
	string tmp;
	for(int i=1; i<=100000; i++) {
		tmp = to_string(i);
		buf += tmp;
	}
}


int main() {
	input(cin);
	
	method();

	bool flag = false;
	int large_size = buf.size();
	int size = N.size();
	
	for(int i=0; i<large_size-size+1; i++) {
		
		for(int j=0; j<size; j++) {
			if(buf[i+j] != N[j]) {
				break;
			}
			if(j == size-1) flag = true;
		}

		if(flag == true) {
			cout <<  i+1 << endl;
			break;
		}
	}
	
	// cout << buf << endl;
	// cout << buf.size() << endl;
	return 0;
}
