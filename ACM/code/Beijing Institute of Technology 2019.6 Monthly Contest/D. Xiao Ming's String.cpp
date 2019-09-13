#include <iostream>
#include <algorithm>
using namespace std;
struct letter_t
{
    char ch;
    int cnt;
};
bool operator<(letter_t a, letter_t b)
{
    return a.cnt > b.cnt;
}
char str[100010];
letter_t letter[26];
/*
void print(void)
{
    for (int i = 0; i < 26; i++)
    {
        if (letter[i].cnt)
            printf("%c %d\n", letter[i].ch, letter[i].cnt);
    }
    putchar('\n');
}
*/
int finddiff(int ch)
{
    // printf("called\n");
    int rest = 0;
    for (int i = 0; i < 26; i++)
    {
        rest += letter[i].cnt;
        if (letter[i].ch != ch && letter[i].cnt != 0)
        {
            letter[i].cnt--;
            char ret = letter[i].ch;
            if (letter[i].cnt < letter[i + 1].cnt)
            {
                sort(letter, letter + 26);
            }

            // printf("return %c\n", ret);
            // print();
            return ret;
        }
    }
    if (rest == 0)
    {
        // printf("return 0\n");
        // print();

        return 0;
    }
    else
    {
        // printf("return -1\n");
        // print();

        return -1;
    }
}
int main(void)
{
    for (int i = 0; i < 26; i++)
    {
        letter[i].ch = i + 'a';
    }

    char ch;
    while ((ch = getchar()) != '\n')
    {
        letter[ch - 'a'].cnt++;
    }
    // print();
    sort(letter, letter + 26);
    // print();
    str[0] = finddiff(0);
    for (int i = 0; (ch = finddiff(str[i])); i++)
    {
        if (ch == -1)
        {
            puts("NO");
            return 0;
        }
        str[i + 1] = ch;
    }
    puts(str);
    return 0;
}