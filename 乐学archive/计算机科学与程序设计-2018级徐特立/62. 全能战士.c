#include <stdio.h>
int main(int argc, char const *argv[])
{
    int total, skill_1, skill_2, skill_3, skill_1_2, skill_1_3, skill_2_3, skill_1_2_3;
    scanf("%d%d%d%d%d%d%d",
          &total, &skill_1, &skill_2, &skill_3, &skill_1_2, &skill_2_3, &skill_1_3);
    skill_1_2_3 = total + skill_1_2 + skill_1_3 + skill_2_3 - skill_1 - skill_2 - skill_3;
    printf("%d\n", skill_1_2_3);
    return 0;
}
