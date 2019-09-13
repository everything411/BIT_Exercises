#include <iostream>
#include <string.h>
using namespace std;
char str1[100010];
char str2[100010];
char rev1[100010];
char rev2[100010];
char ans[100010];
char revans[100010];
int len1;
int len2;
int anslen;
void outputspace(int n)
{
    for (int i = 0; i < n; i++)
    {
        putchar(' ');
    }
}
void outputline(int n)
{
    for (int i = 0; i < n; i++)
    {
        putchar('-');
    }
}
int main(void)
{
    int T;
    cin >> T;
    int flag;
    for (int i = 0; i < T; i++)
    {
        flag = 0;
        memset(ans, 0, sizeof(ans));
        memset(revans, 0, sizeof(ans));
        memset(rev1, 0, sizeof(ans));
        memset(rev2, 0, sizeof(ans));

        scanf("%s%s", str1, str2);

        len1 = strlen(str1);
        len2 = strlen(str2);

        for (int i = 0; i < len1; i++)
        {
            rev1[i] = str1[len1 - i - 1] - '0';
        }

        for (int i = 0; i < len2; i++)
        {
            rev2[i] = str2[len2 - i - 1] - '0';
        }

        for (int i = 0; i < max(len1, len2); i++)
        {
            ans[i] = (rev1[i] + rev2[i] + flag) % 2 + '0';
            flag = (rev1[i] + rev2[i] + flag) / 2;
        }
        if (flag)
        {
            ans[max(len1, len2)] = '1';
        }
        anslen = strlen(ans);
        for (int i = 0; ans[i]; i++)
        {
            revans[i] = ans[anslen - i - 1];
        }
        revans[anslen] = 0;
        // puts(ans);
        // puts(revans);
        outputspace(anslen - len1 + 2);
        printf("%s\n", str1);
        putchar('+');
        outputspace(anslen - len2 + 1);
        printf("%s\n", str2);
        outputline(anslen + 2);
        putchar('\n');
        printf("  %s\n", revans);
    }

    return 0;
}