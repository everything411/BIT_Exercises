#include <iostream>
#include <bitset>
#include <cctype>
using namespace std;
struct phone_dup_map
{
    int phone;
    short count;
};
bool operator>(phone_dup_map a, phone_dup_map b)
{
    return a.phone > b.phone;
}
bitset<1000000> startwith_three;
bitset<1000000> startwith_six;
phone_dup_map phone_dup[1600];
char phone_str[32];
const int ch2int[] =
    {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, -1, 7, 7, 8, 8, 8, 9, 9, 9, -1};
int dup_count;
int find_dup(int phone_num)
{
    for (int i = 0; i < dup_count; i++)
    {
        if (phone_dup[i].phone == phone_num)
        {
            // printf("DEBUG: return %d\n", i);
            return i;
        }
    }
    // printf("DEBUG: return %d\n", -1);

    return -1;
}

template <typename T>
void select_sort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int index_nmax = 0;
        for (int j = 1; j < len - i; j++)
        {
            if (arr[j] > arr[index_nmax])
            {
                index_nmax = j;
            }
        }
        if (index_nmax != len - i - 1)
        {
            T tmp = arr[index_nmax];
            arr[index_nmax] = arr[len - i - 1];
            arr[len - i - 1] = tmp;
        }
    }
}
int main(void)
{
    // int num_count;
    bool has_error = false;
    int phone_num;
    int phone_index;
    puts("Error:");
    while (scanf("%s", phone_str) != EOF)
    {
        // num_count = 0;.
        phone_num = 0;
        for (int i = 0; phone_str[i]; i++)
        {
            if (phone_str[i] == '-')
            {
                continue;
            }
            else if (isupper(phone_str[i]))
            {
                if (ch2int[phone_str[i]] == -1)
                {
                    has_error = true;
                    puts(phone_str);
                    break;
                }
                else
                {
                    phone_num *= 10;
                    phone_num += ch2int[phone_str[i] - 'A'];
                }
            }
            else
            {
                phone_num *= 10;
                phone_num += phone_str[i] - '0';
            }
        }
        // printf("DEBUG: %d\n", phone_num);
        if (phone_num / 1000000 == 3)
        {
            if (startwith_three.test(phone_num % 1000000))
            {
                if ((phone_index = find_dup(phone_num)) == -1)
                {
                    phone_dup[dup_count].phone = phone_num;
                    phone_dup[dup_count].count = 2;
                    dup_count++;
                }
                else
                {
                    phone_dup[phone_index].count++;
                }
            }
            else
            {
                startwith_three.set(phone_num % 1000000, true);
            }
        }
        else if (phone_num / 1000000 == 6)
        {
            if (startwith_six.test(phone_num % 1000000))
            {
                if ((phone_index = find_dup(phone_num)) == -1)
                {
                    phone_dup[dup_count].phone = phone_num;
                    phone_dup[dup_count].count = 2;
                    dup_count++;
                }
                else
                {
                    phone_dup[phone_index].count++;
                }
            }
            else
            {
                startwith_six.set(phone_num % 1000000, true);
            }
        }
        else
        {
            has_error = true;
            puts(phone_str);
        }
    }
    if (!has_error)
    {
        puts("Not found.\n");
    }
    else
    {
        puts("");
    }
    puts("Duplication:");
    if (dup_count == 0)
    {
        puts("Not found.");
    }
    else
    {
        select_sort(phone_dup, dup_count);
        for (int i = 0; i < dup_count; i++)
        {
            printf("%03d-%04d %d\n", phone_dup[i].phone / 10000, phone_dup[i].phone % 10000, phone_dup[i].count);
        }
    }
    return 0;
}