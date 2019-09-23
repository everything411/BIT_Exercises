#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct shoot
{
    int Nm;
    double func_val[10];
    double eps;
    bool operator<(const struct shoot &a)
    {
        return eps < a.eps;
    }
    void calc_eps(void)
    {
        extern int y[10];
        double tmp;
        eps = 0;
        for (int i = 0; i < 10; i++)
        {
            tmp = y[i] - func_val[i];
            eps += tmp * tmp;
        }
    }
};
int x[10];
int y[10];
double R;
double N0;
int l, r;
double f(double Nm, double x)
{
    double a = N0 * exp(R * x);
    return Nm * a / (Nm - N0 + a);
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", x + i);
    }
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", y + i);
    }
    scanf("%lf%lf%d%d", &R, &N0, &l, &r);
    shoot *Fx = new shoot[r - l + 1];
    for (int i = l; i <= r; i++)
    {
        Fx[i - l].Nm = i;
        for (int j = 0; j < 10; j++)
        {
            Fx[i - l].func_val[j] = f(i, x[j]);
        }
        Fx[i - l].calc_eps();
    }
    sort(Fx, Fx + r - l + 1);
    printf("%d\n", Fx[0].Nm);
    delete[] Fx;
    return 0;
}
