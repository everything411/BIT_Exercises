#include <iostream>
#include <string>
using namespace std;
int c[30][30];
void C() //求组合数
{
    for (int i = 0; i <= 26; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main()
{
    string s;
    C();
    while (cin >> s)
    {
        int len = s.length();
        int i;
        for (i = 1; i < len; i++)
        {
            if (s[i] <= s[i - 1])
                break;
        }
        if (i < len)
        {
            cout << 0 << endl;
            continue;
        }
        int sum = 0;
        for (i = 1; i < len; i++)
            sum += c[26][i]; //长度比该串短的先加上

        for (i = 0; i < len; i++) //从高位进行处理对于每一位处理到该位的前一个，比如该位为‘d'，就处理到c
        {
            char ch = i == 0 ? 'a' : (s[i - 1] + 1);
            for (char j = ch; j < s[i]; j++)
                sum += c['z' - j][len - 1 - i];
        }
        cout << sum + 1 << endl; //加上串本身
    }
    return 0;
}