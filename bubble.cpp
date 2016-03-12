#include <iostream>
using namespace std;

// Swap function which is pretty usful sorting algorithms below..
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}


/*
Insertion Sort : 삽입 정렬

algorithm : 배열의 정렬된 영역과 정렬되지 않은 부분을 만들어낸다. 
매번 순환을 할 때마다 다음으로 정렬되지 않은 원소가 정렬된 영역에서 제자리를 찾아가게 된다.

- 자료 이동량을 최소화 할 수 있는 알고리즘, 항목 들이 열거되어 있는 경우 순서가 반대로 되어있는 원소 쌍 (i < j , list[i] > list[j]) 를 매번 제거한다.
*/

void insertionSort(int *list, int n) {
	int j;
	for(int i=1; i<n; i++) {
		j = i;
		while((j>0) &&(list[j] < list[j-1]) {
			swap(list[j], s[j-1]);
			j--;
		}
	}

}
/*

Selection Sort : 선택정렬 

배열을 정렬된 부분과 정렬되지 않은 부분으로 나누며 매번 순환문을 돌 때마다 정렬되지 않은 부분에서 가장 작은 원소를 찾아서 정렬된 영역 맨 뒤로 이동한다.

선택정렬에서는 비교작업을 매우 많이 해야 되지만 데이터 이동횟수만 가지고 보면 상당히 효율적이다. 이 알고리즘에서는 n-1번만 원소를 맞바꾸면 되는데, 이것도 최악의 경우에만 그렇다.

즉 역순으로 정렬된 것을 다시 원하는 순서대로 정렬하는 경우에만 그렇다. 또한 고급 자료구조가 얼마나 강력한지를 보여주는 좋은 예가 되기도 한다. 배열의 정렬되지 않은 부분을 효율적인
우선 순위 큐를 써서 관리하면 O(n^2) -> )(nlogn)인 힙 정렬이 된다. 
*/
void selectionSort(int* list, int n) {
	 //Counter;
	int min; // 최소값의 인덱스

	for(int i =0; i<n; i++) {
		min = i;
		for(int j=i+1; j<n; j++) {
			if(list[j] < list[min]) {
				min = j;
			}
		}
		swap(list[i], list[min]);
	}
}



void bubbleSort(int *list, int flag) {
	//flag 1 means ascending order , 0 descending order.

	switch(flag) {
		case 1:
				for(int i=0; i< ( sizeof(list)/sizeof(*list) ); i++) {
					for(int j=0; j< ( sizeof(list)/sizeof(*list) ); j++) {
						if(list[i] > list[i+1] ) {
							swap(list[i], list[i+1]);
						} 
					}
				}
				break;
		
				for(int i=0; i< (sizeof(list)/sizeof(*list)); i++) {
					for(int j=0; j< (sizeof(list)/sizeof(*list)); j++) {
						if(list[i] < list[i+1] ) {
							swap(list[i], list[i+1] );
						} 
					}
				}
				

	}
	
} 

void quickSort(int *list, int left, int right) {
	int i = left,  j = right;
	int tmp;
	int pivot = list[(left + right)/2];

	/* partition */
	while(i <= j) {
		while(list[i] < pivot) 
			i++;
		while(list[j] < pivot)
			j--;
		if(i <= j) {
			swap(list[i], list[j]);
			i++; j--;
		}
		
	}

	/* recursion */
	if(left < j) quickSort(list, left, j);
	if(i < right) quickSort(list, i, right);
}

void heapSort(int *list) {

}

void insertionSort(int *list) {

}

int main(int argc, char const *argv[])
{	
	int arr[5] = {5, 3 , 2, 6, 22};
	//quickSort(arr, 0, 4);
	selectionSort(arr, 5);
	for(int i=0; i<5; i++) {
		cout << arr[i] << "\t";
	}
	
	return 0;
}