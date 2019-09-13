#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct student_t
{
    char id[21];
    int total_score;
};
bool operator<(student_t a, student_t b)
{
    if (a.total_score != b.total_score)
        return a.total_score > b.total_score;
    else
        return strcmp(a.id, b.id) < 0;
}
student_t student_list[1000];
int main(int argc, char const *argv[])
{
    int student_count, question_count, min_score;
    int solved_count;
    int question_id;
    int score[10] = {0};
    int ans_count;
    while (scanf("%d%d%d", &student_count, &question_count, &min_score) && student_count)
    {
        ans_count = 0;
        memset(student_list, 0, sizeof(student_t) * student_count);
        for (int i = 0; i < question_count; i++)
        {
            scanf("%d", &score[i]);
        }
        for (int i = 0; i < student_count; i++)
        {
            scanf("%s%d", student_list[i].id, &solved_count);
            for (int j = 0; j < solved_count; j++)
            {
                scanf("%d", &question_id);
                student_list[i].total_score += score[question_id - 1];
            }
        }
        sort(student_list, student_list + student_count);
        for (int i = 0; i < student_count; i++)
            if (student_list[i].total_score >= min_score)
                ans_count++;
            else
                break;
        printf("%d\n", ans_count);
        for (int i = 0; i < ans_count; i++)
            printf("%s %d\n", student_list[i].id, student_list[i].total_score);
    }
    return 0;
}
