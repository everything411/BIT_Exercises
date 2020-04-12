#include <iostream>
#include <algorithm>
using namespace std;
int triangle[110][110];
int dp[110][110];
int main(int argc, char const *argv[])
{
    // FILE *in = fopen("input.txt", "r");
    // FILE *out = fopen("output.txt", "w");
    FILE *in = stdin;
    FILE *out = stdout;
    if (!in || !out)
    {
        perror(__FILE__);
        return 1;
    }
    int cnt;
    fscanf(in, "%d", &cnt);
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            fscanf(in, "%d", &triangle[i][j]);
        }
    }
    for (int i = cnt; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    fprintf(out, "%d\n", dp[1][1]);
    // fclose(in);
    // fclose(out);
    return 0;
}
