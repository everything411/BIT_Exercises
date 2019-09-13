/* cannot access '/home/girlfriend': No such file or directory */
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int angry_max_day = 0;
    int max_hour = 0;
    int work, study, hours;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d%d", &study, &work);
        hours = study + work;
        if (hours > 9 && hours > max_hour)
        {
            max_hour = hours;
            angry_max_day = i + 1;
        }
    }
    printf("%d\n", angry_max_day);
    return 0;
}
