#include <stdio.h>
#include <algorithm>
using namespace std;
 
int stack[500001];
int main() {
    int N, Value, N2, Check_Value;
    scanf("%d", &N);//숫자 카드의 개수
 
    for (int i = 0; i < N; i++) {
        scanf("%d", &Value);//숫자 카드 값 입력
        stack[i] = Value;
    }
    sort(stack, stack + N);
    scanf("%d", &N2);//숫자 카드가 있는지 확인할 횟수
 	
    for (int i = 0; i < N2; i++) {
        int right = N - 1, left = 0, mid = (right + left) / 2;
        scanf("%d", &Check_Value);//임의의 숫자 카드
        if(N == 1 && Check_Value == stack[0]) {
        	printf("1 "); 
        	break;
        	} else if (N == 1 && i == N2-1) {
        		printf("0 "); 
        		break;
        	}
        while (left != right) {
            if (Check_Value == stack[mid]) {
                printf("1 ");
                break;
            }
            else if (Check_Value > stack[mid]) {
                if (mid == left&&Check_Value != stack[right]) {
                    printf("0 ");
                    break;
                }
                else if (mid == left&&Check_Value == stack[right]) {
                    printf("1 ");
                    break;
                }
                left = mid;
                mid = (left + right) / 2;
            }
            else if (Check_Value < stack[mid]) {
                right = mid;
                mid = (left + right) / 2;
            }
        }
    }
}