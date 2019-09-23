#include <iostream>
using namespace std;
int li[1010];
int main(int argc, char const *argv[])
{
    int n;
    int cnt = 0;
    int has_unread = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> li[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (li[i - 1] == 1 && li[i] == 1)
        {
            has_unread = 1;
            cnt++;
        }
        else if (li[i] == 1)
        {
            has_unread = 1;
            cnt += 2;
        }
    }
    if (has_unread)
    {
        cnt--;
    }
    cout << cnt << endl;
    return 0;
}
