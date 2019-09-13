#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct stu_t
{
    string id;
    int score;
};
stu_t students[10001];
int stu_cnt, min_score, min_rank;
int money = 0;
int curr_money = 50;
bool operator<(stu_t a, stu_t b)
{
    if (a.score == b.score)
    {
        return a.id < b.id;
    }
    else
    {
        return a.score > b.score;
    }
}
int get_rank(stu_t stu)
{
    int ret = 0;
    for (int i = 0; i < stu_cnt; i++)
    {
        if (stu.score < students[i].score)
        {
            ret++;
        }
    }

    return ret + 1;
}
int main(int argc, char const *argv[])
{

    scanf("%d%d%d", &stu_cnt, &min_score, &min_rank);
    for (int i = 0; i < stu_cnt; i++)
    {
        cin >> students[i].id >> students[i].score;
    }
    sort(students, students + stu_cnt);

    for (int i = 0; i < stu_cnt; i++)
    {
        if (students[i].score >= min_score)
        {
            money += curr_money;
        }
        else
        {
            if (curr_money == 20)
            {
                break;
            }
            else
            {
                curr_money = 20;
                min_score = 60;
                i--;
            }
        }
    }
    printf("%d\n", money);

    if (stu_cnt <= 5)
    {

        for (int i = 0; i < stu_cnt; i++)
        {

            cout << get_rank(students[i]) << " " << students[i].id << " " << students[i].score << endl;
        }
    }
    else
    {
        int temp_rank;
        for (int i = 0; i < stu_cnt && (temp_rank = get_rank(students[i])) <= 5; i++)
        {
            cout << temp_rank << " " << students[i].id << " " << students[i].score << endl;
        }
    }

    return 0;
}
