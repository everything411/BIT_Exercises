#include <iostream>
#include <algorithm>
using namespace std;
struct gift_t
{
    int volume;
    int index;
    int containing = -1; // index sorted
    int contained = -1;  // index sorted
};
bool operator<(const gift_t &a, const gift_t &b)
{
    return a.volume > b.volume;
}
gift_t gift[100010];
int gift_index_ans[100010];
int main(void)
{
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &gift[i].volume);
        gift[i].index = i + 1;
    }
    sort(gift, gift + count);
    int max_gift_pos = 0;
    for (int i = 0; i < count; i++)
    {
        if (gift[max_gift_pos].volume >= 2 * gift[i].volume)
        {
            gift[max_gift_pos].containing = i;
            gift[i].contained = max_gift_pos;
            max_gift_pos++;
        }
    }
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        if (gift[i].contained == -1)
        {
            total++;
        }
    }
    printf("%d\n", total);
    int gift_index;
    for (int i = 0; i < count; i++)
    {
        if (gift[i].containing == -1)
        {
            total = 0;
            gift_index = i;
            while (true)
            {
                gift_index_ans[total++] = gift[gift_index].index;
                if (gift[gift_index].contained != -1)
                {
                    gift_index = gift[gift_index].contained;
                }
                else
                {
                    break;
                }
            }
            printf("%d ", total);
            for (int i = 0; i < total - 1; i++)
            {
                printf("%d ", gift_index_ans[i]);
            }
            printf("%d\n", gift_index_ans[total - 1]);
        }
    }
    return 0;
}
