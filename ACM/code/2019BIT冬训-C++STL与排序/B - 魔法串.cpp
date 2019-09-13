#include <iostream>
#include <cstring>
#define SEARCH_HEAD 0
#define SEARCH_NEXT 1
using namespace std;
char change_list[128][2];
char find_char(char ch, bool mode)
{
    static int pos;
    if (mode == SEARCH_HEAD)
        pos = 0;
    while (change_list[pos][0])
    {
        if (change_list[pos][0] == ch)
        {
            return change_list[pos++][1];
        }
        pos++;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int case_count;
    int change_count;
    char str_to[1001];
    char str_from[1001];
    int to_len, from_len;
    int to_pos;
    char change_to;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        to_pos = 0;
        memset(change_list, 0, sizeof(change_list));
        scanf("%s%s%d", str_to, str_from, &change_count);
        for (int i = 0; i < change_count; i++)
            scanf("%c %c", &change_list[i][0], &change_list[i][1]);
        to_len = strlen(str_to);
        from_len = strlen(str_from);
        {
            if (str_from[i] == str_to[to_pos])
            {
                to_pos++;
            }
            else
            {
                change_to = find_char();
            }
        }
    }

    return 0;
}
