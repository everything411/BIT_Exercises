// from http://xzm2001.cn/archives/51/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w,h,xc,yc,r,x1,x2,y1,y2,xmin,xmax,ymin,ymax;
    cin >> w >> h >> xc >> yc >> r >> x1 >> y1 >> x2 >> y2;
    if (y1 < y2)
    {
        xmin = x1; xmax = x1 + y2 - y1;
        ymin = y1; ymax = y2;
    }
    if (y1 > y2)
    {
        xmin = x2 - y1 + y2; xmax = x2;
        ymin = y2; ymax = y1;
    }
    if (x1 < x2)
    {
        xmin = x1; xmax = x2;
        ymin = y2 - x2 + x1; ymax = y1;
    }
    if (x1 > x2)
    {
        xmin = x2; xmax = x1;
        ymin = y1; ymax = y1 + x1 - x2;
    }
    assert(xmax - xmin == ymax - ymin && xmax > xmin && ymax > ymin);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            bool flag = false;
            flag = flag || ((i - xc) * (i - xc) + (j - yc) * (j - yc) <= r * r);
            flag = flag || ((xmin <= i && i <= xmax) && (ymin <= j && j <= ymax));
            if (flag) printf("/"); else printf("\\");
        }
        printf("\n");
    }
    return 0;
}