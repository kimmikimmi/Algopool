#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
struct student {
	char name[11];
	int kor;
	int eng;
	int math;
};

int N;
vector<student> student_info;

void input(istream& in) {
	
}

void method() {

}

int main() {
	string name;
	student s;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%s %d %d %d", s.name, &s.kor, &s.eng, &s.math);
		student_info.push_back(s);
	}
	stable_sort(student_info.begin(), student_info.end(), [](student s1, student s2) {
			if(s1.kor == s2.kor) {
				if(s1.eng == s2.eng) {
					if(s1.math == s2.math) {
						return strcmp(s1.name, s2.name)>0 ? false : true;
					}
					return s1.math > s2.math;
				}
				return s1.eng < s2.eng;
			}
			return s1.kor > s2.kor;});
	for(auto& it : student_info) 
		printf("%s \n", it.name);
	return 0;
}
