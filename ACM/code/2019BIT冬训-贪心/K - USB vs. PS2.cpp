#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(long long i, long long j)
{
    return i > j;
}
int main(int argc, char const *argv[])
{
    long long USB_only, PS2_only, both_compat;
    long long mouse_count, mouse_price;
    long long temp_price;
    long long USB_count, PS2_count;
    char temp_name[30];
    scanf("%lld%lld%lld%*lld", &USB_only, &PS2_only, &both_compat);
    vector<long long> PS2_price;
    vector<long long> USB_price;
    while (~scanf("%lld%s", &temp_price, temp_name))
    {
        mouse_count = mouse_price = 0;
        switch (temp_name[0])
        {
        case 'U':
            USB_price.push_back(temp_price);
            break;
        case 'P':
            PS2_price.push_back(temp_price);
            break;
        default:
            break;
        }
    }
    USB_count = USB_price.size();
    PS2_count = PS2_price.size();
    sort(USB_price.begin(), USB_price.end(), cmp);
    sort(PS2_price.begin(), PS2_price.end(), cmp);
    while (USB_only && USB_count)
    {
        mouse_price += USB_price[USB_count - 1];
        USB_only--, USB_count--, mouse_count++;
    }
    while (PS2_only && PS2_count)
    {
        mouse_price += PS2_price[PS2_count - 1];
        PS2_only--, PS2_count--, mouse_count++;
    }
    while (both_compat && (PS2_count || USB_count))
    {
        if (PS2_count == 0)
        {
            mouse_price += USB_price[USB_count - 1];
            both_compat--, USB_count--, mouse_count++;
        }
        else if (USB_count == 0)
        {
            mouse_price += PS2_price[PS2_count - 1];
            both_compat--, PS2_count--, mouse_count++;
        }
        else if (USB_price[USB_count] > PS2_price[PS2_count])
        {
            mouse_price += PS2_price[PS2_count - 1];
            both_compat--, PS2_count--, mouse_count++;
        }
        else if (USB_price[USB_count] <= PS2_price[PS2_count])
        {
            mouse_price += USB_price[USB_count - 1];
            both_compat--, USB_count--, mouse_count++;
        }
    }
    printf("%lld %lld\n", mouse_count, mouse_price);
    return 0;
}
