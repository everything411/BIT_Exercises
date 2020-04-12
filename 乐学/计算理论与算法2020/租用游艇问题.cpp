#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int r[210][210];
int dp[210];
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
    for (int i = 1; i < cnt; i++)
    {
        for (int j = i + 1; j <= cnt; j++)
        {
            fscanf(in, "%d", &r[i][j]);
        }
    }
    memcpy(dp, r[1], sizeof(dp));
    for (int i = 3; i <= cnt; i++)
    {
        for (int j = 2; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j] + r[j][i]);
        }
    }

    fprintf(out, "%d\n", dp[cnt]);
    // fclose(in);
    // fclose(out);
    return 0;
}
