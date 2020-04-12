//Soloe@csdn 欢迎转载，但请保留
//Written by Soloe@csdn originally with C++
//Rewrite according to original version by everything411 with C
//algorithm is not changed
//fix a bug of forever loop
#include <stdio.h>
#include <string.h>
#define to_num(X) ((X) - 'a')
long long table[10][26]; //查表，将最简形式的编码事先准备好
/**
 * 行号：0 1 2 3 4 ... 24 25 
 * 列号：
 * 0 a b c d e ... y z 
 * 1 ab bc cd de ef ... yz zz 
 * 2 abc bcd cde efg ghi ... xyz zzz 
 * 3 ...
 * 4 ... 
 * 9 abcdefghij ..... qrstuvwxyz ...zzzzz
 **/
int is_valid(char *str)
{
    if (str[1] == 0)
        return 1;
    for (int i = 1; str[i]; i++)
        if (str[i - 1] > str[i])
            return 0;
    return 1;
}
void init_table()
{
    for (int i = 0; i < 26; i++)
    {
        table[0][i] = i + 1; //对应的是 a/b/c/.../z的编码是1-26;
    }
    for (int i = 1; i < 10; i++)
    {
        table[i][0] = table[i - 1][25] + 1; //abc 总是等于上一行（降阶） yz +1
        for (int j = 1; j < 26 - i; j++)
        {
            table[i][j] = table[i][j - 1] + 1 + table[i - 1][25] - table[i - 1][j];
            //cde - bcd = byz + 1 - bcd = 1 + yz - cd
        }
        for (int j = 26 - i; j < 26; j++)
        {
            table[i][j] = table[i][j - 1];
            //因为z2、y3这些不合法，所以无增加编码，都是和前面的最简式子一样的数
        }
    }
    return;
}
long long search_table(char *str)
{
    /* 举例： bdfxz = b4 - c3 + d3 - e2 + f2 - g1 + x1 - y0 + z0 */
    /*
    long long ret = 0;
    int len = strlen(str);
    int temp_i, temp_j;
    for (int i = 0; i < len - 1; i++)
    {
        temp_i = len - i - 1;
        temp_j = to_num(str[i]);
        ret += table[temp_i][temp_j] - table[temp_i - 1][temp_j + 1];
    }
    ret += table[0][to_num(str[len - 1])];
    return ret;
    */
    long long ret = 0;
    int i, j;
    char *p = str;
    int n = strlen(p);
    while (n > 1)
    {
        i = n - 1;
        j = *p - 'a';
        ret += (table[i][j] - table[i - 1][j + 1]);
        n--;
        p++;
    }
    ret += table[0][*p - 'a'];
    return ret;
}
int main(void)
{
    char str[32];
    int count;
    init_table();
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%s", str);
        if (is_valid(str))
            printf("%lld\n", search_table(str));
        else
            puts("0");
    }

    return 0;
}
