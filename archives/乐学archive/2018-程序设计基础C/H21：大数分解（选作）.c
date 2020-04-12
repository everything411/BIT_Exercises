#include <stdio.h>
int main(int argc, char const *argv[])
{
    int number;
    scanf("%d", &number);
    for (int i = 2; i < number; i++)
        while (!(number % i))
        {
            printf("%d\n", i);
            number /= i;
        }
    if (number != 1)
        printf("%d\n", number);
    return 0;
}
