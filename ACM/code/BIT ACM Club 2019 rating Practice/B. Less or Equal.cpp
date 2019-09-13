#include <iostream>
#include <algorithm>
using namespace std;
int numbers[200000];
int main(int argc, char const *argv[])
{
    int total, count;
    scanf("%d%d", &total, &count);
    for (int i = 0; i < total; i++)
    {
        scanf("%d", &numbers[i]);
    }
    sort(numbers, numbers + total);
    if (count != 0)
    {
        if (numbers[count - 1] != numbers[count])
            printf("%d\n", numbers[count - 1]);
        else
            puts("-1");
    }
    else if (numbers[0] == 1)
        puts("-1");
    else
        printf("%d\n", numbers[0] - 1);
    return 0;
}
