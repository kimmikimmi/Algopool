#include <stdio.h>
#define min(a,b)(a<b?a:b)
#define INF 9999999;

int n, m;
int map[1001][1001];
int from, to, w;
 
int tmp, tmp2,max;

int main()
{
    int i, j, kk,k;
 
    //freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &kk);
 
    for (i = 1; i <= n;i++)
    for (j = 1; j <= n;j++)
    if (i != j) map[i][j] = INF;
 
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &from, &to, &w);
        if (map[from][to]>w)
        map[from][to] = w;
    }
 
 
    for (k = 1; k <= n; k++){
        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++) {
                if(map[i][k] == 9999999) 
                    break;
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
 
            }
        }
    }
 
    for (i = 1; i <= n; i++)
    {
        tmp = map[kk][i];
        tmp2 = map[i][kk];
 
        if (max < tmp2 + tmp)
        max = tmp2 + tmp;
 
    }
 
    printf("%d", max);
    return 0;
}
