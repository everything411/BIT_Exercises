#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 1000
using namespace std;
struct node
{
    char data;
    struct node *l;
    struct node *r;
};
char in[MAXN];
char post[MAXN];
void create(node *&root, int postl, int postr, int inl, int inr)
{
    if (postl > postr)
    {
        return;
    }
    root = (node *)calloc(1, sizeof(node));
    root->data = post[postr];
    int index = -1;
    for (int i = inl; i <= inr; i++)
    {
        if (in[i] == post[postr])
        {
            index = i;
            break;
        }
    }
    int lcount = index - inl;
    create(root->l, postl, postl + lcount - 1, inl, index - 1);
    create(root->r, postl + lcount, postr - 1, index + 1, inr);
}
void print(node *root)
{
    queue<node *> q;
    if (root != NULL)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        printf("%c", q.front()->data);
        if (q.front()->l)
        {
            q.push(q.front()->l);
        }
        if (q.front()->r)
        {
            q.push(q.front()->r);
        }
        q.pop();
    }
    putchar('\n');
}
int main(int argc, char const *argv[])
{
    scanf("%s%s", in, post);
    int len = strlen(in);
    node *root;
    create(root, 0, len - 1, 0, len - 1);
    print(root);
    return 0;
}
