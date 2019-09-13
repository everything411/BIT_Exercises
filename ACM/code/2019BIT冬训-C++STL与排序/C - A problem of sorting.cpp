#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
struct person_t
{
    char name[101];
    int birth_year;
};
bool operator<(person_t a, person_t b)
{
    return a.birth_year > b.birth_year;
}
person_t people_list[100];
int main(int argc, char const *argv[])
{
    int T;
    int people_count;
    int len;
    char temp_str[256];
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &people_count);
        getchar();
        memset(people_list, 0, sizeof(person_t) * people_count);
        for (int i = 0; i < people_count; i++)
        {
            fgets(temp_str, 256, stdin);
            len = strlen(temp_str);
            temp_str[--len] = 0;
            temp_str[len - 5] = 0;
            strcpy(people_list[i].name, temp_str);
            people_list[i].birth_year = strtol(&temp_str[len - 4], NULL, 10);
        }
        sort(people_list, people_list + people_count);
        for (int i = 0; i < people_count; i++)
            puts(people_list[i].name);
    }

    return 0;
}
