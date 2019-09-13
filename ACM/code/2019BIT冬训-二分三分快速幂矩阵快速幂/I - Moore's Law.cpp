#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int ori, power;
    scanf("%d%d", &ori, &power);
    printf("%.10Lf\n", ori * pow(1.000000011l, power));
    return 0;
}
