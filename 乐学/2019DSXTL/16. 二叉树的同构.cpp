#include <iostream>
// #include <cassert>
using namespace std;
#define MAXN 100
typedef char Element;
typedef struct BPTNode
{
    Element data;
    int lchild, rchild;
} BNode;
struct BTree
{
    BNode nodes[MAXN];
    int num_node;
    int root;
    void build()
    {
        bool isnroot[MAXN] = {};
        scanf("%d", &num_node);
        char ch1, ch2, ch3;
        for (int i = 0; i < num_node; i++)
        {
            scanf(" %c %c %c", &ch1, &ch2, &ch3);
            nodes[i].data = ch1;
            if (ch2 == '-')
            {
                nodes[i].lchild = -1;
            }
            else
            {
                nodes[i].lchild = ch2 - '0';
                isnroot[nodes[i].lchild] = true;
            }
            if (ch3 == '-')
            {
                nodes[i].rchild = -1;
            }
            else
            {
                nodes[i].rchild = ch3 - '0';
                isnroot[nodes[i].rchild] = true;
            }
        }
        for (int i = 0; i < num_node; i++)
        {
            if (!isnroot[i])
            {
                root = i;
                break;
            }
        }
        // assert(nodes[root].data == 'A');
    }
    bool IsIsomorphic(BTree &tree2)
    {
        return do_check_isomorphic(tree2, this->root, tree2.root);
    }

private:
    bool do_check_isomorphic(BTree &tree2, int root1, int root2)
    {
        if (root1 == -1 && root2 == -1)
        {
            return true;
        }
        else if ((root1 == -1 && root2 != -1) || (root1 != -1 && root2 == -1))
        {
            return false;
        }
        else if (this->nodes[root1].data != tree2.nodes[root2].data)
        {
            return false;
        }
        else if (do_check_isomorphic(tree2, this->nodes[root1].lchild, tree2.nodes[root2].lchild) &&
                 do_check_isomorphic(tree2, this->nodes[root1].rchild, tree2.nodes[root2].rchild))
        {
            return true;
        }
        else if (do_check_isomorphic(tree2, this->nodes[root1].lchild, tree2.nodes[root2].rchild) &&
                 do_check_isomorphic(tree2, this->nodes[root1].rchild, tree2.nodes[root2].lchild))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
BTree tree1, tree2;
int main(int argc, char const *argv[])
{
    tree1.build();
    tree2.build();
    if (tree1.IsIsomorphic(tree2))
    {
        printf("Yes.\n");
    }
    else
    {
        printf("No.\n");
    }
    return 0;
}
