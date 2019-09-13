#include <iostream>
#include <algorithm>
using namespace std;
struct ball_t
{
    int a;
    int b;
    int c;
    int index;
};
bool operator<(ball_t a, ball_t b)
{
    if (a.a != b.a)
    {
        return a.a < b.a;
    }
    else if (a.b != b.b)
    {
        return a.b < b.b;
    }
    else
    {
        return a.c < b.c;
    }
}
ball_t balls[100010];
int main(void)
{
    int cnt;
    int max_d = 0;
    int max_d_1 = 0;
    int max_d_2 = 0;
    int index_1, index_2_1, index_2_2;
    int d_2;
    index_1 = index_2_1 = index_2_2 = -1;

    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> balls[i].a >> balls[i].b >> balls[i].c;
        balls[i].index = i + 1;
        // no need to sort...
        if (balls[i].a < balls[i].b) // a >= b
        {
            swap(balls[i].a, balls[i].b);
        }
        if (balls[i].a < balls[i].c) // a >= c
        {
            swap(balls[i].a, balls[i].c);
        }
        if (balls[i].b < balls[i].c) // b >= c
        {
            swap(balls[i].b, balls[i].c);
        }
    }
    sort(balls, balls + cnt);
    for (int i = 0; i < cnt; i++)
    {
        // max_d_1 = max(max_d_1, balls[i].c); // c is smallest, 2 * r
        if (max_d_1 < balls[i].c)
        {
            max_d_1 = balls[i].c;
            index_1 = balls[i].index;
        }
    }
    max_d = max_d_1;
    for (int i = 0; i < cnt - 1; i++)
    {
        d_2 = -1;
        if (balls[i].a == balls[i + 1].a && balls[i].b == balls[i + 1].b)
        {
            d_2 = min(balls[i].c + balls[i + 1].c, balls[i].b); // check
        }
        max_d_2 = max(max_d_2, d_2);
        if (max_d_2 > max_d)
        {
            max_d = max_d_2;
            index_2_1 = balls[i].index;
            index_2_2 = balls[i + 1].index;
        }
    }
    if (index_2_1 == -1)
    {
        cout << "1" << endl
             << index_1 << endl;
    }
    else
    {
        cout << "2" << endl
             << index_2_1 << endl
             << index_2_2 << endl;
    }
    return 0;
}