#include <stdio.h>
#include <signal.h>
int hexmap[128] = {};
void hexmap_init(void)
{
    hexmap['0'] = 1,
    hexmap['1'] = 2,
    hexmap['2'] = 4,
    hexmap['3'] = 8,
    hexmap['4'] = 16,
    hexmap['5'] = 32,
    hexmap['6'] = 64,
    hexmap['7'] = 128,
    hexmap['8'] = 256,
    hexmap['9'] = 512,
    hexmap['A'] = 1024,
    hexmap['B'] = 2048,
    hexmap['C'] = 4096,
    hexmap['D'] = 8192,
    hexmap['E'] = 16384,
    hexmap['F'] = 32768;
}
char map[16][20];
int rot_map[4][4][4][4][5];
int rot_count[4][4];
void get_row_rot(void)
{
    for (int row = 0; row < 4; row++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        int ans = 0;
                        for (int m = 0; m < 4; m++)
                        {
                            ans |= rot_map[row][0][i][0][m];
                            ans |= rot_map[row][1][j][0][m];
                            ans |= rot_map[row][2][k][0][m];
                            ans |= rot_map[row][3][l][0][m];
                        }
                        // cout << ans << endl;
                        if (ans == 65535)
                        {
                            rot_count[row][0] = i;
                            rot_count[row][1] = j;
                            rot_count[row][2] = k;
                            rot_count[row][3] = l;
                            goto rot_next;
                        }
                    }
                }
            }
        }
    rot_next:;
    }
}
void get_col_rot(void)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    int flag = 1;
                    for (int col = 0; col < 4; col++)
                    {
                        int ans = 0;
                        for (int m = 0; m < 4; m++)
                        {
                            ans |= rot_map[0][col][(rot_count[0][col] + (i << 1)) % 4][m][0];
                            ans |= rot_map[1][col][(rot_count[1][col] + (j << 1)) % 4][m][0];
                            ans |= rot_map[2][col][(rot_count[2][col] + (k << 1)) % 4][m][0];
                            ans |= rot_map[3][col][(rot_count[3][col] + (l << 1)) % 4][m][0];
                        }
                        // cout << ans << endl;
                        if (ans != 65535)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (int col = 0; col < 4; col++)
                        {
                            rot_count[0][col] += i << 1;
                            rot_count[1][col] += j << 1;
                            rot_count[2][col] += k << 1;
                            rot_count[3][col] += l << 1;
                            rot_count[0][col] %= 4;
                            rot_count[1][col] %= 4;
                            rot_count[2][col] %= 4;
                            rot_count[3][col] %= 4;
                            // cout << i << endl
                            //      << j << endl
                            //      << k << endl
                            //      << l << endl;
                        }
                        return;
                    }
                }
            }
        }
    }
    puts("go die!");
    raise(SIGINT);
}
void rot_init(void) // 0 <= args <= 3
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    rot_map[row][col][0][j][k] = hexmap[map[j + row * 4][k + col * 4]];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 3; j >= 0; j--)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        rot_map[row][col][i + 1][3 - j][k] =
                            rot_map[row][col][i][k][j];
                    }
                }
            }
        }
    }
}

int main(void)
{
    hexmap_init();
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        for (int i = 0; i < 16; i++)
        {
            scanf("%s", map[i]);
        }
        rot_init();
        get_row_rot();
        get_col_rot();
        int total_ori = 0, total_rot = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                total_ori += rot_count[i][j];
                total_rot += (rot_count[i][j] + 2) % 4;
            }
        }
        if (total_ori < total_rot)
        {
            printf("%d\n", total_ori);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < rot_count[i][j]; k++)
                    {
                        printf("%d %d\n", i + 1, j + 1);
                    }
                }
            }
        }
        else
        {
            printf("%d\n", total_rot);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < (rot_count[i][j] + 2) % 4; k++)
                    {
                        printf("%d %d\n", i + 1, j + 1);
                    }
                }
            }
        }
    }

    return 0;
}