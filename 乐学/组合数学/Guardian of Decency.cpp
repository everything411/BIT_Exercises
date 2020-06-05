#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 510
using namespace std;

struct BPM
{
    int n, m;
    int G[MAXN][MAXN];
    int left[MAXN];
    bool T[MAXN];

    void init(int n, int m)
    {
        this->n = n;
        this->m = m;
        memset(G, 0, sizeof(G));
    }

    bool match(int u)
    {
        for (int v = 0; v < m; v++)
        {
            if (G[u][v] && !T[v])
            {
                T[v] = true;
                if (left[v] == -1 || match(left[v]))
                {
                    left[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int solve()
    {
        memset(left, -1, sizeof(left));
        int ans = 0;
        for (int u = 0; u < n; u++)
        {
            memset(T, 0, sizeof(T));
            if (match(u))
                ans++;
        }
        return ans;
    }
};

BPM solver;
struct student
{
    int height;
    size_t preferred_music;
    size_t favorite_sport;
};
size_t bkdrhash(const char *str)
{
    size_t hash = 0;
    size_t ch;
    while ((ch = *str++))
    {
        hash = hash * 131 + ch;
    }
    return hash;
}
bool conflict(const student &a, const student &b)
{
    return (abs(a.height - b.height) <= 40 &&
            a.preferred_music == b.preferred_music &&
            a.favorite_sport != b.favorite_sport);
}
struct student girls[MAXN];
struct student boys[MAXN];
int h;
char sex;
char preferred_music[110];
char favorite_sport[110];
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        int girlcount, boycount;
        girlcount = boycount = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d %c%s%s", &h, &sex, preferred_music, favorite_sport);
            if (sex == 'M')
            {
                // boys[boycount++] = {h, bkdrhash(preferred_music), bkdrhash(favorite_sport)};
                boys[boycount].height = h;
                boys[boycount].preferred_music = bkdrhash(preferred_music);
                boys[boycount].favorite_sport = bkdrhash(favorite_sport);
                boycount++;
            }
            else
            {
                // girls[girlcount++] = {h, bkdrhash(preferred_music), bkdrhash(favorite_sport)};
                girls[girlcount].height = h;
                girls[girlcount].preferred_music = bkdrhash(preferred_music);
                girls[girlcount].favorite_sport = bkdrhash(favorite_sport);
                girlcount++;
            }
            solver.init(girlcount, boycount);
            for (int i = 0; i < girlcount; i++)
            {
                for (int j = 0; j < boycount; j++)
                {
                    if (conflict(girls[i], boys[j]))
                    {
                        solver.G[i][j] = 1;
                    }
                }
            }
        }
        printf("%d\n", boycount + girlcount - solver.solve());
    }
    return 0;
}
