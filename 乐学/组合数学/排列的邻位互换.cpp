#include <iostream>
#include <cstring>
#define RIGHT 1
#define LEFT -1
using namespace std;
struct num
{
    int n;
    int dir;
};
struct num numbers[20];
int t;
int n;
int k;
bool is_active(int pos)
{
    int to_pos = pos + numbers[pos].dir;
    return !(to_pos < 0 || to_pos >= n) && numbers[to_pos].n < numbers[pos].n;
}
int max_active()
{
    int k = n;
    for (int i = 0; i < n; i++)
    {
        if (is_active(i) && (numbers[i].n > numbers[k].n))
        {
            k = i;
        }
    }
    return k;
}
void reverse_dir(int pos)
{
    for (int i = 0; i < n; i++)
    {
        if (numbers[i].n > numbers[pos].n)
        {
            numbers[i].dir = -numbers[i].dir;
        }
    }
}

int main(int argc, char const *argv[])
{

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        memset(numbers, 0, sizeof(numbers));
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            numbers[i] = {i + 1, LEFT};
        }
        int active;
        int new_active;
        for (int i = 1; i < k; i++)
        {
            active = max_active();
            new_active = active + numbers[active].dir;
            swap(numbers[active], numbers[new_active]);
            reverse_dir(new_active);
        }
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d ", numbers[i].n);
        }
        printf("%d\n", numbers[n - 1].n);
    }

    return 0;
}
