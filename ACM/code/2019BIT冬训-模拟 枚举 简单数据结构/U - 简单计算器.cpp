#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    double numbers[500];
    double temp;
    double ans;
    char op;
    while (scanf("%lf", &temp))
    {
        int pos = 0;
        numbers[0] = temp;
        op = getchar();
        if (temp == 0.0 && op == '\n') //calc end
            break;
        while (1)
        {
            op = getchar();
            scanf("%lf", &temp);
            if (op == '\n') //expression end
                break;
            switch (op)
            {
            case '+':
                numbers[++pos] = temp;
                break;
            case '-':
                numbers[++pos] = -temp; // subtract ~ negative
                break;
            case '*':
                numbers[pos] *= temp;
                break;
            case '/':
                numbers[pos] /= temp;
                break;
            default:
                break;
            }
            if (getchar() == '\n') // ' ' or '\n'
                break;
        }
        ans = 0;
        for (; pos >= 0; pos--)
        {
            ans += numbers[pos];
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
