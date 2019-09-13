#include <iostream>
using namespace std;
int main(void)
{
    int num;
    scanf("%d", &num);
    switch (num)
    {
    case 0:
        puts("None");
        break;
    case 1:
        puts("XiZhiTang");
        break;
    case 2:
        puts("YingHuaTang");
        break;
    default:
        puts("BigBoLang");
        break;
    }
    return 0;
}