#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int count;
    scanf("%d", &count);
    vector<int> segments(count);

    for (auto &i : segments)
    {
        scanf("%d", &i);
    }
    sort(segments.begin(), segments.end());

    for (auto i = segments.begin(); i + 2 != segments.end(); i++)
    {
        if (*i + *(i + 1) > *(i + 2) && *(i + 1) + *(i + 2) > *i && *i + *(i + 2) > *(i + 1))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
