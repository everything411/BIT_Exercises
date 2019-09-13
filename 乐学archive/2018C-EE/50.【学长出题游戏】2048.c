#include <stdio.h>
inline int is_operatable(int matrix[4][4]);
int main(int argc, char const *argv[])
{
    int matrix[4][4];
    int case_count;
    int zero_flag, win_flag;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        win_flag = zero_flag = 0;
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
            {
                scanf("%d", &matrix[j][k]);
                if (matrix[j][k] == 0)
                    zero_flag = 1;
                if (matrix[j][k] == 2048)
                    win_flag = 1;
            }
        if (!win_flag && (zero_flag || is_operatable(matrix)))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
int is_operatable(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i][j] == matrix[i][j + 1])
                return 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (matrix[i][j] == matrix[i + 1][j])
                return 1;
    return 0;
}