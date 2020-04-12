#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int i, j, count, curr_count;
    double mass;
    double atom_mass[4] = {12.01, 1.008, 16.00, 14.01};
    scanf("%d", &count);
    char formula[100];
    char *pos;
    for (i = 0; i < count; i++)
    {
        int atom_count[4] = {0};
        scanf("%s", formula);
        mass = 0.0;
        for (pos = formula; *pos != 0; pos++)
        {
            if (isalpha(*pos))
            {
                if (isdigit(*(pos + 1)))
                    curr_count = atoi(pos + 1);
                else
                    curr_count = 1;
                switch (*pos)
                {
                case 'C':
                    atom_count[0] += curr_count;
                    break;
                case 'H':
                    atom_count[1] += curr_count;
                    break;
                case 'O':
                    atom_count[2] += curr_count;
                    break;
                case 'N':
                    atom_count[3] += curr_count;
                    break;
                }
            }
        }
        for (j = 0; j < 4; j++)
        {
            mass += atom_count[j] * atom_mass[j];
        }
        printf("%.3f\n", mass);
    }
    return 0;
}
