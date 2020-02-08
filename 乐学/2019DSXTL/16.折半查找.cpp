#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct data
{
    int d;
    string s;
    bool operator<(const data &b) const
    {
        return d < b.d;
    }
    bool operator==(const data &b) const
    {
        return d == b.d;
    }
};
struct data records[1000];
char str[100];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int d;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%[^\n]\n", &d, str);
        records[i] = {d, str};
    }
    sort(records, records + n);
    for (int i = 0; i < n; i++)
    {
        printf("(%d%s)", records[i].d, records[i].s.c_str());
    }
    putchar('\n');
    int f;
    scanf("%d", &f);
    struct data *res = find(records, records + n, (struct data){f, ""});
    if (res == records + n)
    {
        puts("error");
    }
    else
    {
        printf("(%d%s)\n", res->d, res->s.c_str());
    }
    return 0;
}
