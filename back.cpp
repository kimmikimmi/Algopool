#include <iostream>
#include <cmath>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
 
void queens(int);
bool promising(int);
int n;
int col[255]={0,};
 
FILE *inputFile, *outputFile;
 

int main() {
    char fileName[255];
 
    printf("input num? ");
    scanf("%d", &n);
    queens(0);
}
 
void printResult() {
    
    printf("result : ");
    for(int i = 1; i<=n; i++) printf("%d ", col[i]);
    //exit(1);
}
 
void queens(int i) {
   
    if(promising(i)) {
        if(i == n) printResult();
        else
            for(int j = 1; j <= n; j++) {
                col[i+1] = j;
                queens(i+1);
            }
    }
}
 
bool promising(int i) { // 직선, 대각선으로 만나는지 검사
    int k = 1;
    bool promising = true;
    while(k < i && promising) {
        if(col[i] == col[k] || abs(col[i]-col[k]) == abs(i-k))
            promising = false; // zero means impossible
        k++;
    }
    return promising;
}


