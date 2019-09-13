#include <stdio.h>
//BUG0 when total == 1 will loop forever
//BUG1 when value == 1 game() always returns zero
//BUG2 when value > total game() may return zero
//BUGFIX add if statement for BUG0 and BUG1
//BUGFIX fix wrong initial argument 3 of function call and fix the wrong return value of game()
int game(int *child, int total, int from, int value)
{
    //递归大家做游戏
    //total:小孩总数，from：从下标为 from 的小孩开始报数，value:报数值
    int curr = 0; //j:当前报数值
    int count = 0;
    int ans = -2;
    if (total == 1)
    {
        return -1;
    }

    if (value == 1)
    {
        return total;
    }

    do
    {
        if (child[from] != 0) //报数小孩不能为空
        {
            curr++;
            if (curr == value) //报数到退出值
            {
                child[from] = 0; //该小孩退出队
                fprintf(stderr, "child %d out queue\n", from);
            }
            from++;            //报数
            if (from >= total) //当前报数者超出范围
                from = 0;      //循环到队首
        }
        else
        {
            while (child[from] == 0) //跳过已出队者
            {
                from++;
                if (from >= total)
                    from = 0;
            }
        }
    } while (curr < value); //报数一次，退出一个小孩

    for (int i = 0; i < total; i++) //统计还在队内的小孩个数
    {
        if (child[i] != 0)
        {
            ans = child[i];
            count++;
        }
    }

    if (count == 1) //剩一个小孩结束递归
    {
        return ans; //返回队中最后一人编号
    }

    while (child[from] == 0) //计算下次开始报数小孩
    {
        from++;
        if (from >= total)
        {
            from = 0;
        }
    }

    return game(child, total, from, value); //递归调用报数函数
}
int main(void)
{
    int total, value;
    int child[100] = {0};
    scanf("%d%d", &total, &value); //输入小孩总数，报数值
    for (int i = 0; i < total; i++)
        child[i] = i + 1;                                               //给小孩编号
    printf("The left child is NO %d.\n", game(child, total, 0, value)); //从第一个小孩开始报数
    return 0;
}
