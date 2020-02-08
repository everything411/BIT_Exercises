#include <iostream>
#include <cstring>
using namespace std;
struct tree
{
    char tree[1 << 6];
    int len;
    int leaf;
    void create()
    {
        memset(tree, '#', sizeof(tree));
        scanf("%s", tree);
        len = strlen(tree);
        tree[len] = '#';
        leaf = leaf_count(0);
        for (int i = 1; i < (1 << 16); i <<= 1)
        {
            if (i - 1 >= len)
            {
                len = i - 1;
                break;
            }
        }
    }
    int leaf_count(int index)
    {
        static int ans = 0;
        if (index >= len)
        {
            return 0;
        }
        // printf("%*c\n", 4 * index + 1, tree[index]);
        if (tree[index] != '#' && tree[2 * index + 1] == '#' && tree[2 * index + 2] == '#')
        {
            ans++;
        }
        leaf_count(2 * index + 1);
        leaf_count(2 * index + 2);
        return ans;
    }
    void print(int index, int blank)
    {
        if (index >= len || tree[index] == '#')
        {
            return;
        }
        printf("%*c\n", 4 * blank + 1, tree[index]);
        print(2 * index + 1, blank + 1);
        print(2 * index + 2, blank + 1);
    }
    void pre_order(int index)
    {
        if (index >= len || tree[index] == '#')
        {
            return;
        }
        putchar(tree[index]);
        pre_order(2 * index + 1);
        pre_order(2 * index + 2);
    }
    void in_order(int index)
    {
        if (index >= len || tree[index] == '#')
        {
            return;
        }
        in_order(2 * index + 1);
        putchar(tree[index]);
        in_order(2 * index + 2);
    }
    void post_order(int index)
    {
        if (index >= len || tree[index] == '#')
        {
            return;
        }
        post_order(2 * index + 1);
        post_order(2 * index + 2);
        putchar(tree[index]);
    }
    void swap()
    {
        /**
         * 1 2
         * 3 5
         * 7 11
         * 15 23
         **/
        /**
         * 0
         * 1 2
         * 3 4 5 6
         * 7 8 9 10 11 12 13 14
         * 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
         **/
        for (int i = 2; i - 1 <= len; i <<= 1)
        {
            for (int j = i - 1; j < i - 1 + (i >> 1); j++)
            {
                ::swap(tree[j], tree[(i << 1) - 1 - (j - i + 1) - 1]);
            }
        }
    }
};
struct tree tree;
int main(int argc, char const *argv[])
{
    tree.create();
    puts("BiTree");
    tree.print(0, 0);
    printf("pre_sequence  : ");
    tree.pre_order(0);
    putchar('\n');
    printf("in_sequence   : ");
    tree.in_order(0);
    putchar('\n');
    printf("post_sequence : ");
    tree.post_order(0);
    putchar('\n');
    printf("Number of leaf: %d\n", tree.leaf);
    tree.swap();
    puts("BiTree swapped");
    tree.print(0, 0);
    printf("pre_sequence  : ");
    tree.pre_order(0);
    putchar('\n');
    printf("in_sequence   : ");
    tree.in_order(0);
    putchar('\n');
    printf("post_sequence : ");
    tree.post_order(0);
    putchar('\n');
    return 0;
}
