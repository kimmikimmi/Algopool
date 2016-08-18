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


void input(std::istream& pin) {

}

int method() {
	return 0;
}

int main() {
	cin >> N;
	
	string channel;
	int kbs1, kbs2;
	vector<string> channels;	
	for(int i=0; i<N; i++) {
		cin >> channel;
		channels.push_back(channel);
	}
	

	//channel KBS1 -> 0th
	//channel KBS2 -> 1th 
	int kbs2_flag = -1;
	for(int i=0; i<N; i++) {
		if(channels[i] == "KBS2") 
			kbs2_flag = i;
		if(channels[i] == "KBS1") {
			for(int j=0; j<i; j++) printf("4");
			if(kbs2_flag != -1) {
			   kbs2_flag++;
			   for(int j=0; j<kbs2_flag; j++) printf("1");
			   for(int j=1; j<kbs2_flag; j++) printf("4");
			}	
			break;	
		}
		else {
			//move down	
			printf("1"); 
		}
	}
	if(kbs2_flag == -1) {
		if(channels[1] == "KBS2") return 0;

		for(int i=0; i<N; i++) {	
			if(channels[i] == "KBS2") 
				for(int j=1; j<i; j++) printf("4");
			else 	
				printf("1"); 
		}
	}

	


	return 0;
}
