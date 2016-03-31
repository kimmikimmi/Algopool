#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> line[7];
int finger_move;
int num_notes;
int num_prets;

struct Note {
	friend istream& operator >> (istream& in, Note &rhs) ;
	int l;
	int p;
	Note(int al, int ap) : l(al), p(ap) {}
	Note() = default;

};

istream& operator >> (istream& in, Note &rhs) {
		in >> rhs.l >> rhs.p;

		return in;
}

ostream& operator << (ostream& out, Note &rhs) {
	out << rhs.l << ", " << rhs.p << endl;
	return out;
}

void read_note(istream& cin, Note &note) {
	cin >> note;
}

void process() {
	int finger_cnt = 0;
	cin >> num_notes >> num_prets;
	Note note;	

	for(int i=0; i<num_notes; i++) {
		read_note(cin, note);
		
		if(!line[note.l].empty()) {
			int max_pret = line[note.l].top();
			if(max_pret < note.p) {
				line[note.l].push(note.p);
				finger_cnt++;
				//cout << "1 " << note << endl;

			} else if(max_pret == note.p) {
				//cout << "2 " << note << endl;
			} else {
				while(!line[note.l].empty() && line[note.l].top() > note.p) {
						
						finger_cnt++;
						line[note.l].pop();
						//cout << "3 " << note << endl;
				} 
				if(!line[note.l].empty() &&line[note.l].top() == note.p) continue;
				line[note.l].push(note.p);
				finger_cnt++;
				//cout << "end of 3" << endl;
			}

		} else {
			line[note.l].push(note.p);
			finger_cnt++;
			//cout << "4 " << note << endl;
		}
	}
	cout << finger_cnt;
}

void method() {
}

int main() {
	process();
	return 0;
}
