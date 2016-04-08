#include <iostream>
#include <vector>
#include <string>

using namespace std;


// A vector to store datas from std::in
std::vector<string> strings;
std::vector<string> r_strings;
string numChar = "9";
int n_of_lines;
/*
@param : null
@return : null
@description : void input func which is gonna get values from std:in. 
	in the order of # of lines and n strings. 
	store to the vector<string> strings 
*/
void input() noexcept{ 
	string tempString;
	cin >> n_of_lines;

	for(int i=0; i<n_of_lines; i++) {
		cin >> tempString;
		strings.push_back(tempString);
	}


}
string getReverseStr(string str) noexcept{
	string r_str;

	for(auto r_iter = str.rbegin(); r_iter != str.rend(); r_iter++) {
		r_str.push_back(*r_iter);
	}
	
	return r_str;
}


int calculate() {
	int val = 0;
	int bIndex = 0;
	int biggest = 0;
	// sort in reverse order.
	for(int i=0; i<strings.size(); i++) {
		r_strings.push_back(getReverseStr(strings[i]));
	}

	//calculate with using r_strings.
	for(int i=0; i<r_strings.size(); i++) {

		if(biggest < r_strings[i].size()) {
			biggest = r_strings[i].size();
			bIndex = i;
		}
	}

	r_strings[bIndex].replace(r_strings[bIndex].begin(), r_strings[bIndex].begin()+1, numChar);
	
	return val;
}






int main(int argc, char const *argv[])
{
	input();
	calculate();
	for(int i=0; i<strings.size(); i++) {
		cout << r_strings[i] << endl;
	}
 // std::string str ("now step live...");
 // cout << str.size() << endl;
 // string temp = getReverseStr(str);
 //  cout << temp << " " << temp.size() << endl;
 	return 0;
}