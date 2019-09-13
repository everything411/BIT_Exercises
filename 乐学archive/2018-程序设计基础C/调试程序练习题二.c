#include <stdio.h>
//BUG append same character
extern char *gets(char *);
void combn(char *str_append, char *str_origin) //将a字符串的第一个字符插入b字符串
{                                              //a:待合并的字符串的首地址，b:合并后的字符串的首地址
    int str_origin_pos = 0;
    int str_tmp_pos = 0;
    if (*str_append == '\0') //待合并的字符串是空字符串，递归结束
        return;
    while (str_origin[str_origin_pos] != '\0') //找到b字符串中第一个不小于a[0]的字符b[j]
    {
        if (*str_append >= str_origin[str_origin_pos])
            str_origin_pos++;
        else
            break;
    }
    if (str_origin_pos && str_origin[str_origin_pos - 1] == *str_append)
    {
        combn(str_append + 1, str_origin);
        return;
    }
    if (str_origin[str_origin_pos] == '\0') //如果b[j]是字符串结束标志
    {
        str_origin[str_origin_pos] = *str_append; //将字符a[0]插在b字符串的串尾
        str_origin[str_origin_pos + 1] = '\0';
    }
    else if (*str_append < str_origin[str_origin_pos]) //将字符a[0]插入原b[j]处
    {
        str_tmp_pos = str_origin_pos;
        while (str_origin[str_tmp_pos] != '\0') //找到原b字符串尾
            str_tmp_pos++;
        while (str_tmp_pos >= str_origin_pos) //b[j]及后面的所有字符后移一个位置
        {
            str_origin[str_tmp_pos + 1] = str_origin[str_tmp_pos];
            str_tmp_pos--;
        }
        str_origin[str_origin_pos] = *str_append; //将a[0]插在b[j]处
    }

    combn(str_append + 1, str_origin); //递归调用comb函数，插入a字符串的下一个字符
    return;
}

int main()
{
    int count;
    char str_append[100] = {0};
    char str_origin[1000] = {0}; //sa保存新输入的字符串，sc保存合并后的字符串
    fprintf(stderr, "Number of strings n:");
    scanf("%d ", &count); //输入待合并的字符串的个数
    for (int i = 0; i < count; i++)
    {
        gets(str_append);              //读入一个字符串
        combn(str_append, str_origin); //将字符串sa合并到字符串sc中
    }
    fprintf(stderr, "Combined:");
    printf("%s\n", str_origin); //输出合并后的字符串
    return 0;
}
