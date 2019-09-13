#include <iostream>
#include <algorithm>
using namespace std;
struct attack
{
    int time;
    int value;
};
bool operator<(const attack &a, const attack &b)
{
    return a.time < b.time;
}
attack attacks[5010];
attack attacks_sorted[5010];
int immunity_len[5010];
int main(void)
{
    int people_count, immunity_count;
    int sorted_count = 0;
    int val_total = 0;
    cin >> people_count >> immunity_count;
    for (int i = 0; i < people_count; i++)
    {
        cin >> attacks[i].time >> attacks[i].value;
    }
    for (int i = 0; i < immunity_count; i++)
    {
        cin >> immunity_len[i];
    }
    sort(attacks, attacks + people_count);
    attacks_sorted[0] = attacks[0];
    val_total = attacks[0].value;
    for (int i = 1; i < people_count; i++)
    {
        val_total += attacks[i].value;
        if (attacks[i].time != attacks_sorted[sorted_count].time)
        {
            sorted_count++;
            attacks_sorted[sorted_count] = attacks[i];
        }
        else
        {
            attacks_sorted[sorted_count].value += attacks[i].value;
        }
    }
    sorted_count++;
    int max_val = 0;
    int head_pos, tail_pos;
    int curr_val;
    for (int i = 0; i < immunity_count; i++)
    {
        curr_val = max_val = 0;
        head_pos = tail_pos = 0;
        for (int j = 0; j < sorted_count; j++)
        {
            tail_pos = j;
            curr_val += attacks_sorted[tail_pos].value;
            while (attacks_sorted[tail_pos].time - attacks_sorted[head_pos].time >= immunity_len[i])
            {
                curr_val -= attacks_sorted[head_pos].value;
                head_pos++;
            }
            max_val = max(max_val, curr_val);
        }

        cout << val_total - max_val << endl;
    }

    return 0;
}