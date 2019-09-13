/**
   >.<嘤嘤~ 
**/
#include <stdio.h>
#include <stdlib.h>
const int SIG_CUTE = -0x66CCFF;
int cmp(const void *i, const void *j);
int find_closest(int value, int count, int rp_list[count]);

int main(int argc, char const *argv[])
{
    int rp_value;
    int count;
    int be_cute_index;
    scanf("%d%d", &count, &rp_value);
    int rp_list[count];
    for (int i = 0; i < count; i++)
        scanf("%d", rp_list + i);
    qsort(rp_list, count, sizeof(int), cmp);
    for (int i = 0; i < count; i++)
    {
        be_cute_index = find_closest(rp_value, count, rp_list);
        if (be_cute_index == SIG_CUTE)
        {
            rp_value += count - i;
            break;
        }
        else
        {
            rp_list[be_cute_index] = SIG_CUTE;
            rp_value += 2;
        }
    }
    printf("%d\n", rp_value);
    return 0;
}
int find_closest(int value, int count, int rp_list[count])
{
    for (int i = count - 2; i >= 0; i--)
    {
        if (rp_list[i] != SIG_CUTE && (value <= rp_list[i] && value >= rp_list[i + 1]))
        {
            fprintf(stderr, ">.<嘤嘤~ at index %d with RP %d\n", i, rp_list[i]);
            return i;
        }
    }
    fprintf(stderr, ">.<嘤嘤~\n");
    return SIG_CUTE;
}
int cmp(const void *i, const void *j)
{
    return *(const int *)i < *(const int *)j ? 1 : -1;
}