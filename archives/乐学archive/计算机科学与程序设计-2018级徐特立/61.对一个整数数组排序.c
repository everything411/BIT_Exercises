/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
#include <stdlib.h>

int resort(int *pa[], int num);

int main(int argc, char *argv[])
{

    int a[100];
    int num;

    int *pa[100];
    scanf("%d", &num);

    int i = 0;
    for (i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
        pa[i] = &a[i];
    }

    resort(pa, num);

    for (i = 0; i < num; i++)
    {
        printf("%d\n", *pa[i]);
    }

    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */
int compare(const void *data_1, const void *data_2)
{
    return **(const int **)data_1 - **(const int **)data_2 > 0 ? 1 : -1;
}
int resort(int *pa[], int num)
{
    qsort(pa, num, sizeof(int *), compare);
    return 0;
}