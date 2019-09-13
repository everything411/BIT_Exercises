#include<iostream>
#include<algorithm>
using namespace std;

#define eps 1e-6
double search()
{
    double left = LEFT, right = RIGHT, mid;
    while (right – left > eps)
    {
        mid = (right + left) / 2;
        if (fun(mid) > 0)
            left = mid;
        else
            right = mid;
    }
    return mid;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
