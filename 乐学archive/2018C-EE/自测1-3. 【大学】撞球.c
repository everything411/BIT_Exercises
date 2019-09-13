#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int pos = 0;
    double ans_x, ans_y;
    double ans;
    double width, length;
    double computer_x, computer_y;
    double player_x, player_y;
    int forward, back, left, right;
    char buffer[2000];
    scanf("%lf%lf%lf%lf%lf%lf%s", &width, &length, &computer_x, &computer_y, &player_x, &player_y, buffer);
    ans_x = ans_y = 0;
    forward = back = left = right = -1;
    for (; buffer[pos]; pos++)
        switch (buffer[pos])
        {
        case 'F':
            if (back == forward && back == -1)
                ans_y += computer_y;
            else
                ans_y += length;
            forward = pos;
            break;
        case 'B':
            if (back == forward && back == -1)
                ans_y += length - computer_y;
            else
                ans_y += length;
            back = pos;
            break;
        case 'L':
            if (left == right && left == -1)
                ans_x += computer_x;
            else
                ans_x += width;
            left = pos;
            break;
        case 'R':
            if (left == right && left == -1)
                ans_x += width - computer_x;
            else
                ans_x += width;
            right = pos;
            break;
        }
    if (left == right && left == -1)
        ans_x += fabs(player_x - computer_x);
    else if (left == -1 && right != -1)
        ans_x += width - player_x;
    else if (left != -1 && right == -1)
        ans_x += player_x;
    else if (left > right)
        ans_x += player_x;
    else
        ans_x += width - player_x;
    if (back == forward && back == -1)
        ans_y += fabs(player_y - computer_y);
    else if (back == -1 && forward != -1)
        ans_y += player_y;
    else if (back != -1 && forward == -1)
        ans_y += length - player_y;
    else if (forward > back)
        ans_y += player_y;
    else
        ans_y += length - player_y;
    ans = sqrt(ans_x * ans_x + ans_y * ans_y);
    printf("%.4lf\n", ans);
    return 0;
}
