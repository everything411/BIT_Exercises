#include <iostream>
#include <stack>
#include <cstring>
#define MAXN 110
using namespace std;
struct PosType
{
    int r;
    int c;
};
struct SElemType
{
    int di;
    int ord;
    struct PosType seat;
};
int maze[MAXN][MAXN];
stack<SElemType> s;
int Pass(int MyMaze[MAXN][MAXN], struct PosType CurPos)
{
    return !MyMaze[CurPos.r][CurPos.c];
}
void FootPrint(int MyMaze[MAXN][MAXN], struct PosType CurPos)
{
    MyMaze[CurPos.r][CurPos.c] = 2;
}
void MarkPrint(int MyMaze[MAXN][MAXN], struct PosType CurPos)
{
    MyMaze[CurPos.r][CurPos.c] = 3;
}

struct PosType NextPos(struct PosType CurPos, int Dir)
{
    struct PosType ReturnPos;
    switch (Dir) // down right up left
    {
    case 1:
        ReturnPos.r = CurPos.r + 1;
        ReturnPos.c = CurPos.c;
        break;
    case 2:
        ReturnPos.r = CurPos.r;
        ReturnPos.c = CurPos.c + 1;
        break;
    case 3:
        ReturnPos.r = CurPos.r - 1;
        ReturnPos.c = CurPos.c;
        break;
    case 4:
        ReturnPos.r = CurPos.r;
        ReturnPos.c = CurPos.c - 1;
        break;
    }
    return ReturnPos;
}

int MazePath(int maze[MAXN][MAXN], struct PosType start, struct PosType end)
{
    stack<SElemType> S;
    PosType curpos;
    int curstep;
    SElemType e;

    curpos = start;
    curstep = 1;
    do
    {
        if (Pass(maze, curpos))
        {
            FootPrint(maze, curpos);
            e.di = 1;
            e.ord = curstep;
            e.seat = curpos;
            S.push(e);
            if (curpos.r == end.r && curpos.c == end.c)
            {
                s = S;
                return true;
            }
            curpos = NextPos(curpos, 1);
            curstep++;
        }
        else
        {
            if (!S.empty())
            {
                e = S.top();
                S.pop();
                while (e.di == 4 && !S.empty())
                {
                    MarkPrint(maze, e.seat);
                    e = S.top();
                    S.pop();
                }
                if (e.di < 4)
                {
                    e.di++;
                    S.push(e);
                    curpos = NextPos(e.seat, e.di);
                }
            }
        }
    } while (!S.empty());
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%*d%d", &n);
    memset(maze, 0x3f, sizeof(maze));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    PosType start = {1, 1};
    PosType end = {n, n};
    SElemType t;
    if (MazePath(maze, start, end))
    {
        stack<SElemType> s2;
        while (!s.empty())
        {
            t = s.top();
            s2.push(t);
            // printf("%d,%d\n", t.seat.r, t.seat.c);
            s.pop();
        }
        while (!s2.empty())
        {
            t = s2.top();
            printf("<%d,%d> ", t.seat.r, t.seat.c);
            s2.pop();
        }
        putchar('\n');
    }
    else
    {
        puts("There is no solution!");
    }

    return 0;
}
