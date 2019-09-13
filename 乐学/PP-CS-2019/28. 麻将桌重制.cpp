#include <iostream>
#include <cmath>
using namespace std;
struct point
{
    int x;
    int y;
    void set(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
struct vec
{
    int x;
    int y;
    void set(point _from, point _to)
    {
        x = _to.x - _from.x;
        y = _to.y - _from.y;
    }
    int operator^(const vec &b)
    {
        return this->x * b.x + this->y * b.y;
    }
};

struct circle
{
    point o;
    int r;
    int d_r;
    circle(int _x, int _y, int _r)
    {
        o.set(_x, _y);
        r = _r;
        d_r = r * r;
    }
    bool test(point p)
    {
        int a = abs(o.x - p.x);
        int b = abs(o.y - p.y);
        int dis = a * a + b * b;
        return dis <= d_r;
    }
};
struct square
{
    point p1, p2, p3, p4;
    int len;
    square(int _x1, int _y1, int _x2, int _y2)
    {
        p1.set(_x1, _y1);
        p3.set(_x2, _y2);
        p2.set((p1.x - p1.y + p3.x + p3.y) / 2, (p1.x + p1.y - p3.x + p3.y) / 2);
        p4.set((p1.x + p1.y + p3.x - p3.y) / 2, (-p1.x + p1.y + p3.x + p3.y) / 2);
    }
    bool test(point p)
    {
        vec a, b;
        a.set(p1, p2);
        b.set(p1, p);
        int AB_AE = a ^ b;
        a.set(p2, p3);
        b.set(p2, p);
        int BC_BE = a ^ b;
        a.set(p3, p4);
        b.set(p3, p);
        int CD_CE = a ^ b;
        a.set(p4, p1);
        b.set(p4, p);
        int DA_DE = a ^ b;
        return AB_AE >= 0 && BC_BE >= 0 && CD_CE >= 0 && DA_DE >= 0;
    }
};

int main(void)
{
    int w, h;
    int x, y, r;
    int x1, x2, y1, y2;
    scanf("%d%d", &w, &h);
    scanf("%d%d%d", &x, &y, &r);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    circle c(x, y, r);
    square s(x1, y1, x2, y2);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (s.test({i, j}) || c.test({i, j}))
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