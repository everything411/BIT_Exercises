#include <stdio.h>
#include <stdlib.h>
int compare(const void *, const void *);
int main(int argc, char const *argv[])
{
    int count = 0;
    int scores[1024] = {0};
    int sum = 0;
    while (~scanf("%d", &scores[count++]))
        ;
    qsort(scores, --count, sizeof(int), compare);
    for (int i = 1; i < count - 1; i++)
        sum += scores[i];
    printf("Canceled Max Score:%d\n"
           "Canceled Min Score:%d\n"
           "Average Score:%d\n",
           scores[count - 1], scores[0], sum / (count - 2));
    return 0;
}
int compare(const void *i, const void *j)
{
    return (int)*((const int *)i) - (int)*((const int *)j);
}