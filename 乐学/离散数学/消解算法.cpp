#include <iostream>
#include <algorithm>
#include <set>
#include <cctype>
#include <cstring>
#define EXPR_NONE 0x0
#define EXPR_TRUE 0x1
#define EXPR_FALSE 0x2
#define alphabet(ch) ((ch) - 'a')
using namespace std;
struct expr
{
    int8_t val[32];
    unsigned long long hashval;

    expr()
    {
        memset(this, 0, sizeof(expr));
    }
    bool operator==(const expr &s) const
    {
        return s.hashval == hashval;
    }
    bool operator<(const expr &s) const
    {
        return s.hashval < hashval;
    }
    void hash()
    {
        hashval = 0;
        for (int i = 0; i < 26; i++)
        {
            hashval |= val[i];
            hashval <<= 2;
        }
    }
    bool is_lambda() const
    {
        return hashval == 0;
    }
    bool can_res(const struct expr &s) const
    {
        int res_pair = 0;
        for (int i = 0; i < 26; i++)
        {
            if ((val[i] | s.val[i]) == (EXPR_TRUE | EXPR_FALSE))
            {
                res_pair++;
            }
        }
        return res_pair == 1;
    }
    struct expr res_with(const struct expr &s) const
    {
        struct expr result;
        for (int i = 0; i < 26; i++)
        {
            if (((val[i] | s.val[i]) == 0) || ((val[i] | s.val[i]) == (EXPR_TRUE | EXPR_FALSE)))
            {
                continue;
            }
            else if (val[i] == EXPR_NONE)
            {
                result.val[i] = s.val[i];
            }
            else
            {
                result.val[i] = val[i];
            }
        }
        result.hash();
        fprintf(stderr, "Res(): hash@%#llx & hash@%#llx -> hash@%#llx\n", hashval, s.hashval, result.hashval);
        return result;
    }
};
set<struct expr> s0, s1, s2;
void get_expr()
{
    static char str[512];
    char *token;
    const char *delim = "&";
    scanf("%s", str);
    token = strtok(str, delim);
    while (token)
    {
        struct expr expr;
        for (int i = 0; token[i]; i++)
        {
            if (islower(token[i]))
            {
                if (i && token[i - 1] == '!')
                {
                    expr.val[alphabet(token[i])] = EXPR_FALSE;
                }
                else
                {
                    expr.val[alphabet(token[i])] = EXPR_TRUE;
                }
            }
        }
        expr.hash();
        s1.insert(expr);
        token = strtok(NULL, delim);
    }
    // cout << s1.size() << endl;
}
int main(int argc, char const *argv[])
{
    get_expr();
    while (true)
    {
        for (auto &&c1 : s0)
        {
            for (auto &&c2 : s1)
            {
                if (c1.can_res(c2))
                {
                    struct expr result = c1.res_with(c2);
                    if (result.is_lambda())
                    {
                        puts("NO");
                        goto end;
                    }
                    if (s0.find(result) == s0.end() && s1.find(result) == s1.end())
                    {
                        s2.insert(result);
                    }
                }
            }
        }
        for (auto &&c1 : s1)
        {
            for (auto &&c2 : s1)
            {
                if (c1.can_res(c2))
                {
                    struct expr result = c1.res_with(c2);
                    if (result.is_lambda())
                    {
                        puts("NO");
                        goto end;
                    }
                    if (s0.find(result) == s0.end() && s1.find(result) == s1.end())
                    {
                        s2.insert(result);
                    }
                }
            }
        }
        if (s2.size() == 0)
        {
            puts("YES");
            goto end;
        }
        else
        {
            for (auto &&i : s1)
            {
                s0.insert(i);
            }
            s1 = s2;
            s2.clear();
        }
    }

end:
    return 0;
}