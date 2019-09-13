#include <cstdio>
#define SAME 1
#define EAT 2
using namespace std;
int father[300010];
void init(int size)
{
    for (int i = 1; i <= size; i++)
        father[i] = i;
}
int find(int x)
{
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
bool judge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return true;
    else
        return false;
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    father[y] = x;
}
int main(int argc, char const *argv[])
{
    int ans = 0;
    int ani_cnt, sen_cnt;
    int x, y, op;
    scanf("%d%d", &ani_cnt, &sen_cnt);
    init(ani_cnt * 3);

    for (int i = 0; i < sen_cnt; i++)
    {
        scanf("%d%d%d", &op, &x, &y);
        if (x < 1 || y < 1 || x > ani_cnt || y > ani_cnt)
        {
            ans++;
            continue;
        }

        if (op == SAME)
        {
            int find_val_x = find(x);
            if (find_val_x == find(y + ani_cnt) || find_val_x == find(y + 2 * ani_cnt))
            {
                ans++;
                continue;
            }
            else
            {
                unite(x, y);
                unite(x + ani_cnt, y + ani_cnt);
                unite(x + 2 * ani_cnt, y + 2 * ani_cnt);
            }
        }
        else
        {
            int find_val_x = find(x);
            if (find_val_x == find(y) || find_val_x == find(y + 2 * ani_cnt))
            {
                ans++;
                continue;
            }
            else
            {
                unite(x, y + ani_cnt);
                unite(x + ani_cnt, y + 2 * ani_cnt);
                unite(x + 2 * ani_cnt, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}