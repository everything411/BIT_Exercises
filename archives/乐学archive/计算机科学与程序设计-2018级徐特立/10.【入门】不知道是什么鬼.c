#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, ans;
    char ch;
    scanf("%d%d\n%c", &a, &b, &ch);
    
    switch (ch)
    {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            if (b == 0) {
                puts("Go to hell!");
                return 1;
            }
            ans = a / b;
            break;
    }
    
    printf("%d\n", ans);
    return 0;
}
