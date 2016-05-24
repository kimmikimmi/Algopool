#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	분석:
	A 의 주문 1 5 18
	B 의 주문 2 5 25 60
	C 의 주문 19 50 100 200

	box라는 object (int guest_id, int product_id, int box_id)를 이용
	A1, A5, A18 B2.. 등의 형태로 box에 매핑
	
	모든 주문을 vector<box> 에 삽입.

	그리고 box.product_id에 맞추어 vector를 오름차순 정렬후

	벡터의 각각의 인덱스를 3(박스의 수용량) 으로 나눈 몫을
							 각각의 박스의 그룹 아이디로 할당.
*/

/*
간단히 표현하기 위해 input을 아래와 같이 변경
3 <- 고객수
3  <- (3명, 각 고객에 대해 주문항 상품의 개수)
4
5
1 5 18 <- 0 가 주문한 상품 리스트 : A
2 5 25 60 <- 1 가 주문한 상품리스트 : B
19 50 100 101 200 <- 2 가 주문한 상품리스트 : C
*/



struct box
{
	int guest_id;
	int product_id;
	int group_id;
	
	box(int g_id, int p_id, int gr_id) : guest_id(g_id), product_id(p_id), group_id(gr_id) {}
};

int num_guest; // 고객의 수 

std::vector<box> box_vec;

void input(istream& in) {
	in >> num_guest;
	int tmp;
	std::vector<int> tmp_vec;

	for(int i=0; i<num_guest; i++) {
		in >> tmp;
		tmp_vec.push_back(tmp);
	}
	for(auto k : tmp_vec) cout << k << endl;
	int product;
	for(int i=0; i<num_guest; i++) {
		for(int j=0; j<tmp_vec[i]; j++) {
			in >> product;
			box b(i, product, 0);
			box_vec.push_back(b);
		}
	}
}

void method() {
	sort(box_vec.begin(), box_vec.end(), [](box a, box b){
		return a.product_id < b.product_id;
	});
	int size = box_vec.size();
	for(int i=0; i<size; i++) {
		box_vec[i].group_id = i/3 + 1;
	}

}

int main() {
	input(cin);
	method();
	
	int d= 1;
	for(auto k : box_vec) {
		
		cout << "그룹 " << k.group_id << ": " << "상자" << d << "( " << (char)(k.guest_id + 'A') << k.product_id << " )" << endl;
		d++;
	}
	return 0;
}
