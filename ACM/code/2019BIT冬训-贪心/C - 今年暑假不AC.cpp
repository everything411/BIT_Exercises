#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct program_t
{
    int start;
    int end;
};
bool operator<(program_t a, program_t b)
{
    return a.end < b.end;
}
program_t program_list[100];
int main(int argc, char const *argv[])
{
    int count;
    int ans;
    while (scanf("%d", &count) && count)
    {
        ans = 1;
        for (int i = 0; i < count; i++)
            scanf("%d%d", &program_list[i].start, &program_list[i].end);
        sort(program_list, program_list + count);
        for (int i = 0, j; i < count; i = j)
        {
            for (j = i + 1; j < count; j++)
                if (program_list[j].start >= program_list[i].end)
                {
                    ans++;
                    break;
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}
