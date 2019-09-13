#include <stdio.h>
int main(void)
{
    int count;
    char a, b;
    int scoreA, scoreB;
    scoreA = scoreB = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf(" %c %c", &a, &b);
        switch (a)
        {
        case 'g':
            switch (b)
            {
            case 'g':
                // nothing changed
                break;
            case 'c':
                scoreA++;
                break;
            case 'p':
                scoreB++;
                break;
            default:
                break;
            }
            break;
        case 'c':
            switch (b)
            {
            case 'g':
                scoreB++;
                break;
            case 'c':
                // nothing changed
                break;
            case 'p':
                scoreA++;
                break;
            default:
                break;
            }
            break;
        case 'p':
            switch (b)
            {
            case 'g':
                scoreA++;
                break;
            case 'c':
                scoreB++;
                break;
            case 'p':
                // nothing changed
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    printf("%d\n%d\n", scoreA, scoreB);
    return 0;
}