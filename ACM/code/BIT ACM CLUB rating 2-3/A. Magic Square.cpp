#include <iostream>
using namespace std;
char mat[10][10];
void rotate(int cmd, int x, int y)
{
    if (cmd == 'C')
    {
        swap(mat[x + 0][y + 0], mat[x + 0][y + 1]);
        swap(mat[x + 0][y + 0], mat[x + 1][y + 1]);
        swap(mat[x + 0][y + 0], mat[x + 1][y + 0]);
    }
    else
    {
        swap(mat[x + 0][y + 0], mat[x + 1][y + 0]);
        swap(mat[x + 0][y + 0], mat[x + 1][y + 1]);
        swap(mat[x + 0][y + 0], mat[x + 0][y + 1]);
    }
}

int main(int argc, char const *argv[])
{
    int t;
    int r;
    int id, cmd;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &r);
        scanf("%s%s%s", mat[0], mat[1], mat[2]);
        getchar();
        for (int j = 0; j < r; j++)
        {
            id = getchar();
            cmd = getchar();
            getchar();
            switch (id)
            {
            case '1':
                rotate(cmd, 0, 0);
                break;
            case '2':
                rotate(cmd, 0, 1);
                break;
            case '3':
                rotate(cmd, 1, 0);
                break;
            case '4':
                rotate(cmd, 1, 1);
                break;
            default:
                break;
            }
        }
        printf("%s\n%s\n%s\n", mat[0], mat[1], mat[2]);
    }
    return 0;
}
