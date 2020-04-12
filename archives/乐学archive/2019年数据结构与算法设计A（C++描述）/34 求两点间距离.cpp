#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
  private:
    double x;
    double y;

  public:
    friend double get_dist(CPoint &a, CPoint &b);
    CPoint(double __x, double __y)
    {
        x = __x;
        y = __y;
    }
};
double get_dist(CPoint &a, CPoint &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(int argc, char const *argv[])
{
    double x, y;
    cin >> x >> y;
    CPoint point_a(x, y);
    cin >> x >> y;
    CPoint point_b(x, y);
    cout << "Distance=" << get_dist(point_a, point_b) << endl;
    return 0;
}
