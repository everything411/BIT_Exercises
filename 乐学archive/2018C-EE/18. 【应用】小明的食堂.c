#include <stdio.h>
#define main_menu "----- 营业时间 -----\n  1. 早餐\n  2. 中餐\n  3. 晚餐\n  4. 夜宵\n  0. 退出\n请输入选项："
#define midnight_menu "----- 夜宵菜单 -----\n 1. 馄饨，2.50\n 2. 馅饼，1.00\n 3. 茶鸡蛋，0.60\n 4. 鸡蛋饼，3.50\n 0. 选择结束\n请输入选项："
#define breakfast_menu "----- 早餐菜单 -----\n 1. 油条，0.32\n 2. 豆浆，0.70\n 3. 鸡蛋，0.50\n 4. 豆腐脑，1.50\n 5. 小包子，0.50\n 0. 选择结束\n请输入选项："
int main(int argc, char const *argv[])
{
    int main_choice, breakfast_choice, lunch_choice, supper_choice, midnight_choice;
    _Bool main_exit, breakfast_exit, lunch_exit, supper_exit, midnight_exit;
    main_exit = breakfast_exit = lunch_exit = supper_exit = midnight_exit = 0;
    double main_price, breakfast_price, lunch_price, supper_price, midnight_price;
    main_price = breakfast_price = lunch_price = supper_price = midnight_price = 0.0;
    int count;
    do
    {
        printf(main_menu);
        scanf("%d", &main_choice);
        switch (main_choice)
        {
        case 1:
            do
            {
                printf(breakfast_menu);
                scanf("%d", &breakfast_choice);
                switch (breakfast_choice)
                {
                case 1:
                    printf("输入油条数量：");
                    scanf("%d", &count);
                    breakfast_price += 0.32 * count;
                    break;
                case 2:
                    printf("输入豆浆数量：");
                    scanf("%d", &count);
                    breakfast_price += 0.70 * count;
                    break;
                case 3:
                    printf("输入鸡蛋数量：");
                    scanf("%d", &count);
                    breakfast_price += 0.50 * count;
                    break;
                case 4:
                    printf("输入豆腐脑数量：");
                    scanf("%d", &count);
                    breakfast_price += 1.50 * count;
                    break;
                case 5:
                    printf("输入小包子数量：");
                    scanf("%d", &count);
                    breakfast_price += 0.50 * count;
                    break;
                case 0:
                    breakfast_exit = 1;
                    break;
                }
            } while (!breakfast_exit);
            printf("早餐合计：%.2f。\n", breakfast_price);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            do
            {
                printf(midnight_menu);
                scanf("%d", &midnight_choice);
                switch (midnight_choice)
                {
                case 1:
                    printf("输入馄饨数量：");
                    scanf("%d", &count);
                    midnight_price += 2.50 * count;
                    break;
                case 2:
                    printf("输入馅饼数量：");
                    scanf("%d", &count);
                    midnight_price += 1.00 * count;
                    break;
                case 3:
                    printf("输入茶鸡蛋数量：");
                    scanf("%d", &count);
                    midnight_price += 0.60 * count;
                    break;
                case 4:
                    printf("输入鸡蛋饼数量：");
                    scanf("%d", &count);
                    midnight_price += 3.50 * count;
                    break;
                case 0:
                    printf("夜宵合计：%.2f。\n", midnight_price);
                    midnight_exit = 1;
                    break;
                }
            } while (!midnight_exit);
            break;
        case 0:
            main_exit = 1;
            main_price = breakfast_price + lunch_price + supper_price + midnight_price;
            break;
        }
    } while (!main_exit);
    printf("买了这么多美食才花了%.2f。\n", main_price);
    return 0;
}
