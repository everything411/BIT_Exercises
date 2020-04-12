/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>

typedef struct buy
{
    char gname;
    int sname;
    int gprice;
} BUY;

int main()
{
    int i, j, n;
    int min, price[10][3];
    int findm(int n, int price[][3], BUY scheme[]);

    static BUY scheme[3] = {{'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0}};

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &price[i][j]);

    min = findm(n, price, scheme);

    printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min);
    for (i = 0; i < 3; i++)
        printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice);
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */
#include <string.h>
int findm(int count, int price[][3], BUY scheme[])
{
    int shop_flag[count];
    memset(shop_flag, 0, sizeof(shop_flag));
    int ret_val = 0;
    for (int i = 0; i < 3; i++)
        scheme[i].gprice = __INT_MAX__;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (!shop_flag[j] && scheme[i].gprice > price[j][i])
            {
                scheme[i].gprice = price[j][i];
                scheme[i].sname = j + 1;
            }
        }
        shop_flag[scheme[i].sname - 1] = 1;
    }
    for (int i = 0; i < 3; i++)
        ret_val += scheme[i].gprice;
    return ret_val;
}