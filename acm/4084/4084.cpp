#include <stdio.h>
 
int main()
{
    int a, b, c, d,temp;
    int cnt;
 
    for (;;)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        cnt = 0;                                    // 수정1
 
        if (a == 0 && b == 0 && c == 0 && d == 0)
                return 0;
 
        for (;;)
        {
             
 
            if (a == b && a == c && a == d && b == c && b == d && c == d){
                printf("%d\n", cnt);
                break;
            }
                    temp = a;
                    if (a < b)
                        a = b - a;
                    else
                        a = a - b;
 
                    if (b < c)
                        b = c - b;
                    else
                        b = b - c;
 
                    if (c < d)
                        c = d - c;
                    else
                        c = c - d;
 
                    if (d < temp)                // 수정2
                        d = temp - d;
                    else
                        d = d - temp;
 
                    // printf("%d %d %d %d\n", a, b, c, d);
                    cnt++;
        }
    }
    return 0;
}