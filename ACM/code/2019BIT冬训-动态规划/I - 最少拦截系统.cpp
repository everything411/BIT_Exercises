#include <iostream>
#include <cstring>
using namespace std;
int systems[100000];
int main(int argc, char const *argv[])
{
    int missile_count, system_count;
    int missile_height;
    int system_pos;
    while (~scanf("%d", &missile_count))
    {
        memset(systems, 0, sizeof(systems));
        system_count = 0;
        for (int i = 0; i < missile_count; i++)
        {
            scanf("%d", &missile_height);
            for (system_pos = 0; system_pos < system_count; system_pos++)
            {
                if (systems[system_pos] > missile_height)
                {
                    systems[system_pos] = missile_height;
                    break;
                }
            }
            if (system_pos == system_count)
            {
                systems[system_count++] = missile_height;
            }
        }
        printf("%d\n", system_count);
    }
    return 0;
}
