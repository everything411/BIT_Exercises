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
#define INF_PRICE 0x7F66CCFF
#include <string.h>
/* algorithem bug fix */
int findm(int count, int (*price)[3], BUY *scheme)
{
    int min_price_id[3][3]; //[goods][shop_id]
    int temp_price[count][3];
    int shop_flag[count];
    memcpy(temp_price, price, sizeof(temp_price));
    for (int k = 0; k < 3; k++)     //price loop
        for (int i = 0; i < 3; i++) //goods loop
        {
            int min_price = INF_PRICE;
            for (int j = 0; j < count; j++) //shop loop
                if (min_price > temp_price[j][i])
                {
                    min_price = temp_price[j][i];
                    min_price_id[i][k] = j;
                }
            temp_price[min_price_id[i][k]][i] = INF_PRICE;
        }
    int temp_ans_id[3];
    int ans_id[3];
    int total_price = INF_PRICE;
    int tmp_total_price;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                memset(shop_flag, -1, sizeof(shop_flag));
                tmp_total_price = 0;
                if (i != j && j != k && i != k)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (shop_flag[min_price_id[i][l]])
                        {
                            tmp_total_price += price[min_price_id[i][l]][i];
                            shop_flag[min_price_id[i][l]] = 0;
                            temp_ans_id[0] = min_price_id[i][l];
                            break;
                        }
                    }
                    for (int l = 0; l < 3; l++)
                    {
                        if (shop_flag[min_price_id[j][l]])
                        {
                            tmp_total_price += price[min_price_id[j][l]][j];
                            shop_flag[min_price_id[j][l]] = 0;
                            temp_ans_id[1] = min_price_id[j][l];
                            break;
                        }
                    }
                    for (int l = 0; l < 3; l++)
                    {
                        if (shop_flag[min_price_id[k][l]])
                        {
                            tmp_total_price += price[min_price_id[k][l]][k];
                            shop_flag[min_price_id[k][l]] = 0;
                            temp_ans_id[2] = min_price_id[k][l];
                            break;
                        }
                    }
                    if (total_price > tmp_total_price)
                    {
                        total_price = tmp_total_price;
                        for (int i = 0; i < 3; i++)
                            ans_id[i] = temp_ans_id[i];
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        scheme[i].sname = ans_id[i] + 1;
        scheme[i].gprice = price[ans_id[i]][i];
    }
    return total_price;
}