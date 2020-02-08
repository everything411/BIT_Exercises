#include <iostream>
#include <cstring>
using namespace std;
struct tnode
{
    int l;
    int r;
    bool flag;
};
struct tnode tree[50000];
char str[50000];
int main(int argc, char const *argv[])
{
    int n;
    int tp;
    int tnum = 2;
    int len;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        len = strlen(str);
        tp = 1;
        for (int j = 0; j < len; j++)
        {
            if (str[j] == '0')
            {
                if (!tree[tp].l)
                {
                    tree[tp].l = tnum;
                    tp = tnum++;
                    if (j == len - 1)
                    {
                        tree[tp].flag = true;
                    }
                }
                else
                {
                    tp = tree[tp].l;
                    if (tree[tp].flag || j == len - 1)
                    {
                        flag = true;
                        puts(str);
                        goto end;
                    }
                }
            }
            else
            {
                if (!tree[tp].r)
                {
                    tree[tp].r = tnum;
                    tp = tnum++;
                    if (j == len - 1)
                    {
                        tree[tp].flag = true;
                    }
                }
                else
                {
                    tp = tree[tp].r;
                    if (tree[tp].flag || j == len - 1)
                    {
                        flag = true;
                        puts(str);
                        goto end;
                    }
                }
            }
        }
    }
end:
    if (!flag)
    {
        puts("YES");
    }
    return 0;
}
