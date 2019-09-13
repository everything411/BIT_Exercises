#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char encoded[200];
char decoded[200];
int main(int argc, char const *argv[])
{
    int len;
    char *left, *right;
    fgets(encoded, 200, stdin);
    len = strlen(encoded);
    encoded[--len] = 0;
    left = &encoded[0];
    right = &encoded[len - 1];
    if (len & 1)
        for (int i = 0; i < len; i++)
        {
            if (i & 1)
            {
                decoded[i] = *right--;
            }
            else
            {
                decoded[i] = *left++;
            }
        }
    else
        for (int i = 0; i < len; i++)
        {
            if (i & 1)
            {
                decoded[i] = *left++;
            }
            else
            {
                decoded[i] = *right--;
            }
        }
    reverse(decoded, decoded + len);
    puts(decoded);
    return 0;
}
