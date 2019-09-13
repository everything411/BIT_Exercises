#include <iostream>
#include <cmath>
using namespace std;
int tau(int num1, int num2)
{
    return 0;
}
int a[1000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (tau(a[i], a[j]) <= 10)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}