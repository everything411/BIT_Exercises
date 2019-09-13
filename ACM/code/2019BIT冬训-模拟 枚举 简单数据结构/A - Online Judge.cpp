#include <iostream>
#include <cstring>
#define START "START\n"
#define END "END\n"
#define AC "Accepted"
#define WA "Wrong Answer"
#define PE "Presentation Error"
using namespace std;
char temp[5001];
char buffer_std[5001];
char buffer_user[5001];
inline static bool is_blank(char ch)
{
    return ch == ' ' || ch == '\n' || ch == '\t';
}
int main(int argc, char const *argv[])
{
    int case_count;
    int len_std, len_user;
    int buffer_std_pos, buffer_user_pos;
    scanf("%d", &case_count);
    getchar();
    for (int i = 0; i < case_count; i++)
    {
        fgets(temp, 5001, stdin);
        while (fgets(temp, 5001, stdin) && strcmp(temp, END))
            strcat(buffer_std, temp);
        fgets(temp, 5001, stdin);
        while (fgets(temp, 5001, stdin) && strcmp(temp, END))
            strcat(buffer_user, temp);
        len_std = strlen(buffer_std);
        len_user = strlen(buffer_user);
        buffer_std_pos = buffer_user_pos = 0;
        if (strcmp(buffer_std, buffer_user) == 0)
        {
            puts(AC);
        }
        else
        {
            for (int i = 0; i <= len_std; i++)
                if (!is_blank(buffer_std[i]))
                    buffer_std[buffer_std_pos++] = buffer_std[i];
            for (int i = 0; i <= len_user; i++)
                if (!is_blank(buffer_user[i]))
                    buffer_user[buffer_user_pos++] = buffer_user[i];
            if (strcmp(buffer_std, buffer_user) == 0)
                puts(PE);
            else
                puts(WA);
        }
        buffer_std[0] = buffer_user[0] = 0;
    }
    return 0;
}