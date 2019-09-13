// from http://xzm2001.cn/archives/51/
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int a,b;
    while (T--)
    {
        scanf("%d%d", &a, &b);
        if (a >= 13) printf("48000\n");
        else if (a >= 11) printf("36000\n");
        else if (a >= 8) printf("24000\n");
        else if (a >= 6) printf("18000\n");
        else if (a == 5) printf("12000\n");
        else
        {
            int t = (1 << (2 + a)) * 6 * b;
            t = (t / 100 + !!(t % 100)) * 100;
            printf("%d\n",min(t,12000));
        }
    }
    return 0;
}