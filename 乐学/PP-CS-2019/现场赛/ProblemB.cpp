#include <iostream>
#include <cmath>
using namespace std;
struct circle
{
    int x;
    int y;
    int r;
    int d_r;
    circle()
    {
        scanf("%d%d%d", &x, &y, &r);
        d_r = r * r;
    }
    bool test(int _x, int _y)
    {
        int a = abs(x - _x);
        int b = abs(y - _y);
        int dis = a * a + b * b;
        return dis <= d_r;
    }
};
struct square
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    int len;
    square()
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2)
        {
            len = abs(y1 - y2);
            if (y1 <= y2)
            {
                x3 = x1 + len;
                y3 = y1;
                x4 = x2 + len;
                y4 = y2;
            }
            else
            {
                swap(x1, x4);
                swap(y1, y4);
                swap(x3, x2);
                swap(y3, y2);
                x1 = x3 - len;
                y1 = y3;
                x2 = x4 - len;
                y2 = y4;
            }
        }
        else
        {
            len = abs(x1 - x2);
            // swap(x2, x3);
            // swap(y2, y3);
            // swap(x)
            if (x1 <= x2)
            {
                x4 = x2;
                y4 = y2;
                x2 = x1;
                y2 = y1;

                x1 = x2;
                y1 = y2 - len;
                x3 = x4;
                y3 = y4 - len;
            }
            else
            {
                swap(x2, x1);
                swap(y2, y1);
                swap(x2, x3);
                swap(y2, y3);
                x2 = x1;
                y2 = y1 + len;
                x4 = x3;
                y4 = y3 + len;
            }
        }
    }
    bool test(int x, int y)
    {
        bool a = x >= x1 && y >= y1;
        bool b = x >= x2 && y <= y2;
        bool c = x <= x3 && y >= y3;
        bool d = x <= x4 && y <= y4;
        return a && b && c && d;
    }
};

int main(void)
{
    int w, h;
    scanf("%d%d", &w, &h);
    circle c;
    square s;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (s.test(i, j) || c.test(i, j))
            {
                putchar('/');
            }
            else
            {
                putchar('\\');
            }
        }
        putchar('\n');
    }
    return 0;
}