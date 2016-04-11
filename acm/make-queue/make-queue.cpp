#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int n;
std::vector<int> children;
void input(istream& in) {
	int temp;
	in >> n;
	for(int i=0; i<n; i++) {
		in >> temp;
		children.push_back(temp);
	}
	// for(auto v : children) cout << v << endl;
}

int method() {
	int cnt = 0;
	for(int i=1; i<n; i++) {
		if(children[i-1] > children[i]) {
			cout << "find insertion pos at i>" << i << endl;
			for(int j=0; j<i; j++) {
				// auto inert_pos = find_if(children.begin(), children.begin() + i,
				// 	[&](int n) {
				// 		if(n < children[i]) {
				// 			return true;
				// 		} else return false;
				// 	});

				if(children[i] < children[j]) {
					auto pos = children.begin() + j;
					children.insert(pos, children[i]);
					children.erase(children.begin() + i + 1);
					cnt++;
					cout << "insert" << endl;
					cout << i << ", " << j << endl;
					for(const auto &p : children) {

						cout << p << " ";
					}
					cout << endl;
					break;
				}
			}
		}
	}
	return cnt;
}

int main() {
	input(cin);
	cout << method();
	return 0;
}
