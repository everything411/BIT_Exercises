/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

int resort(int (*pa)[COL], int row, int col);

int main(int argc, char *argv[])
{

    int a[ROW][COL];
    //    int num;

    int(*pa)[COL];

    int i = 0, j = 0;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
            scanf("%d", &a[i][j]);
    }
    pa = a;

    resort(a, ROW, COL);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */
int compare(const void *data_1, const void *data_2)
{
    return *(const int *)data_1 - *(const int *)data_2 > 0 ? 1 : -1;
}
int resort(int (*pa)[COL], int row, int col)
{
    for (int i = 0; i < ROW; i++)
        qsort(pa[i], COL, sizeof(int), compare);
    return 0;
}