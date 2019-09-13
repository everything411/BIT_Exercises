#include <iostream>
#include <string>
using namespace std;
int nextval[1000001];
void getnext(string &s)
{
    int len = s.length();
    int j = -1;
    nextval[0] = -1;
    for (int i = 1; i < len; i++)
    {
        if (j != -1 && s[i] != s[j + 1])
        {
            j = nextval[j];
        }
        if (s[i] == s[j + 1])
            j++;
        nextval[i] = j;
    }
}

int kmp_count(string &t, string &w)
{
    getnext(w);
    int n = t.length();
    int m = w.length();
    int j = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j != -1 && t[i] != w[j + 1])
            j = nextval[j];
        if (t[i] == w[j + 1])
            j++;
        if (j == m - 1)
        {
            ans++;
            j = nextval[j];
        }
    }
    return ans;
}
int main(void)
{
    string w, t;
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        cin >> w >> t;
        printf("%d\n", kmp_count(t, w));
    }
    return 0;
}