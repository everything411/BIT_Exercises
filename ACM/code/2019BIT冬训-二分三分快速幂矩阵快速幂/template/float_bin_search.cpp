
#define eps 1e-6
double search(double LEFT, double RIGHT, double (*func)(double))
{
    double left = LEFT, right = RIGHT, mid;
    while (right - left > eps)
    {
        mid = (right + left) / 2;
        if (func(mid) > 0)
            left = mid;
        else
            right = mid;
    }
    return mid;
}