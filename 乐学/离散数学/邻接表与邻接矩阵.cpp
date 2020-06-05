#include <iostream>
#include <cctype>
#include <cassert>
using namespace std;
int c[128];
int mat[128][128];
int main(int argc, char const *argv[])
{
    int start;
    int end;
    while ((start = getchar()) != EOF)
    {
        assert(isprint(start));
        c[start] = 1;
        while ((end = getchar()) != '\n')
        {
            if (end == ' ')
            {
                continue;
            }
            assert(isprint(end));
            c[end] = 1;
            mat[start][end]++;
        }
    }
    int last = 0;
    for (int i = 128; i > 0; i--)
    {
        if (c[i])
        {
            last = i;
            break;
        }
    }
    for (int i = 0; i < 128; i++)
    {
        if (c[i])
        {
            for (int j = 0; j < 128; j++)
            {
                if (c[j])
                {
                    printf("%d%c", mat[i][j], j == last ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}
