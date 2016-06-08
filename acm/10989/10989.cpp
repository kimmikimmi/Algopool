#include <iostream>
using namespace std;
int number[10001];
 
int main()
{
    std::ios_base::sync_with_stdio(false);
    int N, input;
    for(int i=1; i<=10000; i++) number[i] = 0;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        number[input]++;
    }
     
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < number[i]; j++)
        {
            
            printf("%d\n", i);
        }
    }
    return 0;
}