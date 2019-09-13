#include <iostream>
using namespace std;
int father[100010];
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
void union1(int x, int y)
{
    x = find(x);
    y = find(y);
    father[y] = x;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
