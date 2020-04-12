#include<cstdio>
#include<cstring>
#define INF 0x7fffffff
#define MAX 210
int mat[MAX][MAX];
int tax[MAX];
int next[MAX][MAX];
int n;
void floyd()
{
    int i,j,k,t;
    for(k = 1;k <= n; k++)
        for(i = 1;i <= n; i++)
            for(j = 1;j <= n; j++)
            {
                if(mat[i][k] != INF && mat[k][j] != INF)
                {
                    t = mat[i][k] + mat[k][j] + tax[k];
                    if(mat[i][j] > t)
                        mat[i][j] = t,next[i][j] = next[i][k];
                    else if(mat[i][j] == t && next[i][j] > next[i][k])
                        next[i][j] = next[i][k];
                }
            }

}
int main()
{
    int x,i,j;
    while(scanf("%d",&n),n)
    {
        for(i = 1;i <= n; i++)
            for(j = 1;j <= n; j++)
            {
                scanf("%d",&mat[i][j]);
                if(mat[i][j] == -1)mat[i][j] = INF;
                next[i][j] = j;
            }
        for(i = 1;i <= n; i++)
            scanf("%d",&tax[i]);
        floyd();
        while(scanf("%d %d",&i,&j),i!=-1||j!=-1)
        {
            printf("From %d to %d :\n",i,j);
            printf("Path: %d",i);
            x=i;
            while(x!=j)
            {
                printf("-->%d",next[x][j]);
                x=next[x][j];
            }
            printf("\n");
            printf("Total cost : %d\n\n", mat[i][j]);
        }
    }
    return 0;
}