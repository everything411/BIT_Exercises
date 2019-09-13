#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>
#include <csignal>
#include <cstdlib>
#define MAXN 1000
using namespace std;
const char end_text[] = "[/Text]";
int line_num[MAXN * 10];
struct line
{
    char str[MAXN];
    // int len;
    bool read(void)
    {
        char ch;
        int pos = 0;
        while ((ch = getchar()) != '\n')
        {
            str[pos++] = ch;
        }
        if (pos > MAXN)
        {
            raise(SIGFPE);
        }
        str[pos] = 0;
        // len = pos;
        return strcmp(str, end_text) != 0;
    }
};
line buffer;
list<line> text;
list<line>::iterator get_iter(int pos)
{
    pos -= 1;
    auto b = text.begin();
    for (int i = 0; i < pos; i++)
    {
        b++;
    }
    return b;
}
void do_escape(char *str)
{
    int pos = 0;
    char buf[MAXN];
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '\\')
        {
            buf[pos++] = str[++i]; // \\ \/
        }
        else
        {
            buf[pos++] = str[i];
        }
    }
    buf[pos] = 0;
    strcpy(str, buf);
}
void do_insert(char *str, int pos)
{
    line buf;
    strcpy(buf.str, str);
    if (pos > text.size())
    {
        text.push_back(buf);
    }
    else
    {
        text.insert(get_iter(pos), buf);
    }
}
void do_replace_escape_read(char *from, char *to)
{
    int pos = 0;
    char ch;
    getchar(); // a space after cmd
    while ((ch = getchar()) != '/')
    {
        if (ch == '\\')
        {
            from[pos++] = getchar();
        }
        else
        {
            from[pos++] = ch;
        }
    }
    from[pos] = 0;
    pos = 0;
    while ((ch = getchar()) != '\n')
    {
        if (ch == '\\')
        {
            to[pos++] = getchar();
        }
        else
        {
            to[pos++] = ch;
        }
    }
    to[pos] = 0;
}
void do_replace(char *original, char *from, char *to)
{
    char *pos = original;
    int to_len = strlen(to);
    int from_len = strlen(from);
    if (strcmp(from, to))
    {
        while ((pos = strstr(pos, from)))
        {
            memmove(pos + to_len, pos + from_len, strlen(pos + from_len) + 1);
            memmove(pos, to, to_len);
            pos = pos + to_len;
        }
    }
}
void do_delete(int pos)
{
    text.erase(get_iter(pos));
}

void do_merge(int *pos_list, int merge_count)
{
    auto to = get_iter(pos_list[0]);
    for (int i = 1; i < merge_count; i++)
    {
        strcat(to->str, get_iter(pos_list[i])->str);
    }
    pos_list[0] = -1;
    sort(pos_list, pos_list + merge_count);
    for (int i = merge_count - 1; i > 0; i--)
    {
        text.erase(get_iter(pos_list[i]));
    }
}
int do_merge_read(int *pos_list)
{
    int text_len = text.size();
    int pos_list_index = 0;
    char buf[100];
    char ch;
    int pos = 0;
    int tmp;
    while ((ch = getchar()))
    {
        switch (ch)
        {
        case '\n':
        case '/':
            buf[pos] = 0;
            pos = 0;
            tmp = atoi(buf);
            if (tmp <= text_len && tmp > 0)
            {
                pos_list[pos_list_index] = tmp;
                pos_list_index++;
            }
            if (ch == '/')
            {
                break;
            }
            else
            {
                return pos_list_index;
            }
        default:
            buf[pos++] = ch;
            break;
        }
    }
    puts("do_merge_read error");
    return -1;
}
bool do_find(int pos, char *str)
{
    char *src = get_iter(pos)->str;
    return strstr(src, str) != NULL;
}
int main(int argc, char const *argv[])
{
    char str[MAXN * 2];
    char replace_from[MAXN * 2];
    char replace_to[MAXN * 2];
    // list<line> text;
    scanf("[Text]");
    getchar();
    while (buffer.read())
    {
        text.push_back(buffer);
    }
    char cmd;
    int pos;
    int merge_count;
    while ((cmd = getchar()) != EOF)
    {
        switch (cmd)
        {
        case 'i':
            scanf("%d/%[^\n]\n", &pos, str);
            do_escape(str);
            do_insert(str, pos);
            break;
        case 'c':
            do_replace_escape_read(replace_from, replace_to);
            for (auto &i : text)
            {
                do_replace(i.str, replace_from, replace_to);
            }
            break;
        case 'd':
            scanf("%d\n", &pos);
            do_delete(pos);
            break;
        case 'f':
            if ((merge_count = do_merge_read(line_num)) != -1)
            {
                do_merge(line_num, merge_count);
            }
            break;
        case 'q':
            ungetc('q', stdin);
            goto out_cmd;
        default:
            puts("command prase error");
            while ((cmd = getchar()) != '\n')
                ;
            // raise(SIGINT);
            break;
        }
    }
out_cmd:
    for (auto &&i : text)
    {
        puts(i.str);
    }
    while (~scanf("q #%d/%[^\n]\n", &pos, str))
    {
        do_escape(str);
        if (do_find(pos, str))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}
