#include <regex>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cctype>
#define ERROR 9
using namespace std;
char str[1010];
char buf[1010];

int f(int s, char input)
{
    switch (s)
    {
    case 0: // init
        if (isdigit(input))
            return 2;
        if (input == '+' || input == '-')
            return 1;
        if (input == '\0')
            return 8;
        return ERROR;
    case 1: // '+' '-'
        if (isdigit(input))
            return 2;
        return ERROR;
    case 2: // isdigit before 'e'/'E'/'.'

        if (isdigit(input))
            return 2;
        if (input == '.')
            return 3;
        if (input == 'e' || input == 'E')
            return 5;
        if (input == '\0')
            return 8;
        return ERROR;
    case 3: // '.'
        if (isdigit(input))
            return 4;
        return ERROR;
    case 4: // isdigit before 'E'/'e'

        if (isdigit(input))
            return 4;
        if (input == 'e' || input == 'E')
            return 5;
        if (input == '\0')
            return 8;
        return ERROR;
    case 5: // 'e'/'E'

        if (isdigit(input))
            return 7;
        if (input == '+' || input == '-')
            return 6;
        return ERROR;
    case 6: // '+'/'-' after 'E'/'e'

        if (isdigit(input))
            return 7;
        return ERROR;
    case 7: // isdigit after 'E'/'e'/'.'
        if (isdigit(input))
            return 7;
        if (input == '\0')
            return 8;
        return ERROR;
    default:
        return ERROR;
    }
    return ERROR;
}
char *p;
int t;
size_t strl = 0;
int s = 0;
char nxt()
{
    return *p++;
}

int main(int argc, char const *argv[])
{

    scanf("%d", &t);
    getchar(); // '\n'
    for (int i = 0; i < t; i++)
    {
        strl = 0;
        s = 0;
        fgets(str, 1010, stdin);
        for (int i = 0; str[i]; i++)
        {
            if (!isspace(str[i]))
            {
                strl++;
            }
        }
        sscanf(str, "%s", buf);
        if (strlen(buf) != strl)
        {
            goto die;
        }
        p = buf;
        while ((s = f(s, nxt())) != 8 && s != ERROR)
            ;
        if (s == 8)
        {
            // assert(regex_match(buf, regex("([+-]?[0-9]+)([/.][0-9]+)?([Ee][+-]?[0-9]+)?")));
            printf("LEGAL\n");
        }
        else
        {
        die:
            printf("ILLEGAL\n");
        }
    }
    return 0;
}
