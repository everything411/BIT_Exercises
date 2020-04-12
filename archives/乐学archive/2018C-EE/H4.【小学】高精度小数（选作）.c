#include<stdio.h>
int main(void)
{
    int a, b;
    scanf("%d/%d",&a, &b);
    printf("0.");
    for(int i = 0;i < 200 && a;i++)
    {
        printf("%d", a * 10 / b);
        a = a * 10 % b;
    }
    putchar('\n');
    return 0;
}
