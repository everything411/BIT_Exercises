#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        printf("%d\n", (num - 4) % 3);
    }
    return 0;
}
