#include<cstdio>
#include<cstring>
using namespace std;

class trie_t
{
  private:
    int trie[400001][26];
    int sum[400001];
    int len;
    int root;
    int tot;

  public:
    void insert(char *s)
    {
        len = strlen(s);
        root = 0;
        for (int i = 0; i < len; i++)
        {
            int id = s[i] - 'a';
            if (!trie[root][id])
                trie[root][id] = ++tot;
            sum[trie[root][id]]++;
            root = trie[root][id];
        }
    }
    int search(char *s)
    {
        root = 0;
        len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            int id = s[i] - 'a';
            if (!trie[root][id])
                return 0;
            root = trie[root][id];
        }
        return sum[root];
    }
};
trie_t trie;
char *gets(char *s)
{
    int c;
    char *cs;
    cs = s;
    while ((c = getc(stdin)) != EOF && (c != '\n'))
    {
        *cs++ = c;
    }
    if (c == EOF && (cs == s || ferror(stdin)))
    {
        s = NULL;
    }
    else
    {
        *cs = '\0';
    }
    return (s);
}
