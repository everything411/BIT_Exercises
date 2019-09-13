/* this code is from a blog */
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_NUM = 105;
const int MAX_LEN = 105;
char word[MAX_NUM][3];
int visit[MAX_NUM]; //标记该字符串是否访问，防止陷入循环
int wordCount;      //记录单词的个数
bool bResult;       //判断结果

void FormatString(char str[]) //取字符串第一个和最后一个字符
{
    int length = strlen(str);
    word[wordCount][0] = str[0];
    word[wordCount][1] = str[length - 1];
    word[wordCount][2] = '\0';
    wordCount++;
}

void dfs(char ch)
{
    if (bResult)
        return;
    if (ch == 'm')
    {
        bResult = true;
        return;
    }

    for (int k = 0; k < wordCount; k++)
    {
        if (visit[k] == 0 && ch == word[k][0])
        {
            visit[k] = 1;
            dfs(word[k][1]);
            visit[k] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    char strTemp[MAX_LEN];
    while (scanf("%s", strTemp) != EOF)
    {
        bResult = false;
        wordCount = 0;
        memset(visit, 0, sizeof(visit));

        FormatString(strTemp);
        while (true)
        {
            scanf("%s", strTemp);
            if (strTemp[0] == '0')
                break;
            FormatString(strTemp);
        }

        dfs('b'); //从字符'b'开始搜索
        if (bResult)
            printf("Yes.\n");
        else
            printf("No.\n");
    }
    return 0;
}