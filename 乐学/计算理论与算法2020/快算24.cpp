#include <iostream>
#include <cmath>
#define EPS 1e-6
#define TARGET 24.0
using namespace std;
double nums[4];

bool is24(int n)
{
    if (n == 1)
    {
        return fabs(nums[0] - TARGET) < EPS;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double a = nums[i];
            double b = nums[j];
            nums[j] = nums[n - 1];

            nums[i] = a + b;
            if (is24(n - 1))
            {
                return true;
            }
            nums[i] = a - b;
            if (is24(n - 1))
            {
                return true;
            }
            nums[i] = b - a;
            if (is24(n - 1))
            {
                return true;
            }
            nums[i] = a * b;
            if (is24(n - 1))
            {
                return true;
            }
            if (b != 0.0) // oops div by zero
            {
                nums[i] = a / b;
                if (is24(n - 1))
                {
                    return true;
                }
            }
            if (a != 0.0) // oops div by zero
            {
                nums[i] = b / a;
                if (is24(n - 1))
                {
                    return true;
                }
            }
            nums[i] = a;
            nums[j] = b;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%lf%lf%lf%lf", nums, nums + 1, nums + 2, nums + 3))
    {
        if (is24(4))
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}
