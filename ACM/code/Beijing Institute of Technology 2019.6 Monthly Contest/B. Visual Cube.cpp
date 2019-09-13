#include <iostream>
#include <cstring>
using namespace std;
char cube[200][200];
char protect[200000];
int main(void)
{
    int casecnt;
    cin >> casecnt;
    int length, width, height;
    for (int i = 0; i < casecnt; i++)
    {
        cin >> length >> width >> height;
        memset(cube, '.', sizeof(cube));
        // set \0
        for (int i = 0; i < 2 * height + 1 + width * 2; i++)
        {
            cube[i][2 * length + 1 + width * 2] = 0;
        }
        // 画上面
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length + 1; j++)
            {
                cube[i * 2][i * 2 + j * 2] = '+';
                if (j != length)
                {
                    cube[i * 2][i * 2 + j * 2 + 1] = '-';
                }
                cube[i * 2 + 1][i * 2 + j * 2 + 1] = '\\';
            }
        }
        for (int j = 0; j < length + 1; j++)
        {
            cube[width * 2][width * 2 + j * 2] = '+';
            if (j != length)
            {
                cube[width * 2][width * 2 + j * 2 + 1] = '-';
            }
        }
        // 画正面
        int posx, posy;
        posx = width * 2 + 1;
        posy = width * 2;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < length + 1; j++)
            {
                cube[posx + i * 2][posy + j * 2] = '|';
            }
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < length + 1; j++)
            {
                cube[posx + i * 2 + 1][posy + j * 2] = '+';
                if (j != length)
                {
                    cube[posx + i * 2 + 1][posy + j * 2 + 1] = '-';
                }
            }
        }
        // 画侧面
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                cube[j * 2 + 1 + i * 2][i * 2] = '|';
                cube[j * 2 + 1 + i * 2][i * 2 + 1] = '\\';
                cube[j * 2 + 1 + i * 2 + 1][i * 2] = '+';
                if (j == height - 1)
                {
                    cube[j * 2 + 1 + i * 2 + 2][i * 2 + 1] = '\\';
                }
            }
        }

        for (int i = 0; i < 2 * height + 1 + width * 2; i++)
        {
            puts(cube[i]);
        }
    }

    return 0;
}