#include <stdio.h>
int main(int argc, char const *argv[])
{
    const char *time;
    int option;
    printf("--小明作息时间表--\n"
           "  1. 起床洗漱\n"
           "  2. 锻炼身体\n"
           "  3. 早餐\n"
           "  4. 上课\n"
           "  5. 午餐休息\n"
           "  6. 上课\n"
           "  7. 自由活动\n"
           "  8. 晚餐\n"
           "  9. 晚自习\n"
           " 10. 上床休息\n"
           "请输入选项：\n");

    scanf("%d", &option);
    switch (option)
    {
    case 1:
        time = "起床洗漱 6:20\n";
        break;
    case 2:
        time = "锻炼身体 6:30\n";
        break;
    case 3:
        time = "早餐 7:30\n";
        break;
    case 4:
        time = "上午上课 8:00\n";
        break;
    case 5:
        time = "午餐休息 12:00\n";
        break;
    case 6:
        time = "下午上课 13:20\n";
        break;
    case 7:
        time = "自由活动 16:00\n";
        break;
    case 8:
        time = "晚餐 17:30\n";
        break;
    case 9:
        time = "晚自习 19:30\n";
        break;
    case 10:
        time = "上床休息 23:00\n";
        break;
    default:
        time = "选项错误\n";
        break;
    }
    printf(time);
    return 0;
}
