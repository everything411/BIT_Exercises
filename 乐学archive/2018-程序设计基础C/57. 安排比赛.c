#include <stdio.h>
int main(int argc, char const *argv[])
{
    int case_count;
    int team_count;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        scanf("%d", &team_count);
        printf("%d\n", (team_count == 1 ? 0 : (team_count & 1 ? team_count : team_count - 1)));
    }
    return 0;
}
