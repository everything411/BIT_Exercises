#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
long double combinatorial(int i, int j);
int compare(const void *, const void *);
int main(void)
{
    int iphone_num;
    int color[26] = {0};
    char ch;
    int count = 0;
    long double all_situation, right_situation;
    all_situation = right_situation = 0.0;
    scanf("%d", &iphone_num);
    getchar(); //remove '\n'
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            color[ch - 'A']++;
            count++;
        }
    }
    if (iphone_num == 0 || iphone_num > count)
    {
        puts("Dreaming ntflc!");
        return 0;
    }
    qsort(color, 26, sizeof(int), compare);

    for (size_t i = 0; i < 26; i++)
    {
        if (color[i] < iphone_num)
        {
            break;
        }
        else
        {
            right_situation += combinatorial(iphone_num, color[i]);
        }
    }
    all_situation = combinatorial(iphone_num, count);
    printf("%.4llf\n", right_situation / all_situation);
    return 0;
}
long double combinatorial(int i, int j)
{
    long double ret = 1;
    if (i < j - i)
        i = j - i;
    for (int k = i + 1; k <= j; k++)
        ret *= (long double)k;
    for (int l = 1; l <= j - i; l++)
        ret /= (long double)l;
    return ret;
}
int compare(const void *i, const void *j)
{
    return -*(int *)i + *(int *)j;
}