#include <stdio.h>
int main(int argc, char const *argv[])
{
    int count;
    double op1, op2, ans;
    char op;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%lf %c%lf", &op1, &op, &op2);
        switch (op)
        {
        case '+':
            ans = op1 + op2;
            break;
        case '-':
            ans = op1 - op2;
            break;
        case '*':
            ans = op1 * op2;
            break;
        case '/':
            ans = op1 / op2;
            break;
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
