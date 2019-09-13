#include<stdio.h>
int main(int argc, char const *argv[])
{
    int RS;
    scanf("%d", &RS);
    int R = RS / 10 - 1;
    int S = RS % 10 - 1;
    char *R_str[5] = {
    "unreadable.\n",
    "barely readable, occasional words distinguishable.\n",
    "readable with considerable difficulty.\n",
    "readable with practically no difficulty.\n",
    "perfectly readable.\n"
    };
    char *S_str[9] = {
    "Faint signals, barely perceptible, ",
    "Very weak signals, ",
    "Weak signals, ",
    "Fair signals, ",
    "Fairly good signals, ",
    "Good signals, ",
    "Moderately strong signals, ",
    "Strong signals, ",
    "Extremely strong signals, "
    };
    printf("%s%s", S_str[S], R_str[R]);
    return 0;
}
