#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
extern char *gets(char *);
double table[65536];
char tmp[1010];
void init(void)
{
    table['H'] = 1.008;
    table['He'] = 4.003;
    table['Li'] = 6.941;
    table['Be'] = 9.012;
    table['B'] = 10.81;
    table['C'] = 12.01;
    table['N'] = 14.01;
    table['O'] = 16.00;
    table['F'] = 19.00;
    table['Ne'] = 20.18;
    table['Na'] = 22.99;
    table['Mg'] = 24.31;
    table['Al'] = 26.98;
    table['Si'] = 28.09;
    table['P'] = 30.97;
    table['S'] = 32.07;
    table['Cl'] = 35.45;
    table['Ar'] = 39.95;
    table['K'] = 39.10;
    table['Ca'] = 40.08;
    table['Sc'] = 44.96;
    table['Ti'] = 47.88;
    table['V'] = 50.94;
    table['Cr'] = 52.00;
    table['Mn'] = 54.94;
    table['Fe'] = 55.85;
    table['Co'] = 58.93;
    table['Ni'] = 58.69;
    table['Cu'] = 63.55;
    table['Zn'] = 65.39;
    table['Ga'] = 69.72;
    table['Ge'] = 72.59;
    table['As'] = 74.92;
    table['Se'] = 78.96;
    table['Br'] = 79.90;
    table['Kr'] = 83.80;
    table['Rb'] = 85.47;
    table['Sr'] = 87.62;
    table['Y'] = 88.91;
    table['Zr'] = 91.22;
    table['Nb'] = 92.91;
    table['Mo'] = 95.94;
    table['Tc'] = 97.91;
    table['Ru'] = 101.1;
    table['Rh'] = 102.9;
    table['Pd'] = 106.4;
    table['Ag'] = 107.9;
    table['Cd'] = 112.4;
    table['In'] = 114.8;
    table['Sn'] = 118.7;
    table['Sb'] = 121.8;
    table['Te'] = 127.6;
    table['I'] = 126.9;
    table['Xe'] = 131.3;
    table['Cs'] = 132.9;
    table['Ba'] = 137.3;
    table['La'] = 138.9;
    table['Ce'] = 140.1;
    table['Pr'] = 140.9;
    table['Nd'] = 144.2;
    table['Pm'] = 144.9;
    table['Sm'] = 150.4;
    table['Eu'] = 152.0;
    table['Gd'] = 157.3;
    table['Tb'] = 158.9;
    table['Dy'] = 162.5;
    table['Ho'] = 164.9;
    table['Er'] = 167.3;
    table['Tm'] = 168.9;
    table['Yb'] = 173.0;
    table['Lu'] = 175.0;
    table['Hf'] = 178.5;
    table['Ta'] = 180.9;
    table['W'] = 183.9;
    table['Re'] = 186.2;
    table['Os'] = 190.2;
    table['Ir'] = 192.2;
    table['Pt'] = 195.1;
    table['Au'] = 197.0;
    table['Hg'] = 200.6;
    table['Tl'] = 204.4;
    table['Pb'] = 207.2;
    table['Bi'] = 209.0;
    table['Po'] = 209.0;
    table['At'] = 210.0;
    table['Rn'] = 222.0;
    table['Fr'] = 223.0;
    table['Ra'] = 226.0;
    table['Ac'] = 227.0;
    table['Th'] = 232.0;
    table['Pa'] = 231.0;
    table['U'] = 238.0;
    table['Np'] = 237.1;
    table['Pu'] = 244.1;
    table['Am'] = 243.1;
    table['Cm'] = 247.1;
    table['Bk'] = 247.1;
    table['Cf'] = 252.1;
    table['Es'] = 252.1;
    table['Fm'] = 257.1;
    table['Md'] = 258.1;
    table['No'] = 259.1;
    table['Lr'] = 262.1;
    table['Rf'] = 265.1;
    table['Db'] = 268.1;
    table['Sg'] = 271.1;
    table['Bh'] = 270.1;
    table['Hs'] = 277.2;
    table['Mt'] = 276.2;
    table['Ds'] = 281.2;
    table['Rg'] = 280.2;
    table['Cn'] = 285.2;
    table['Nh'] = 284.2;
    table['Fl'] = 289.2;
    table['Mc'] = 288.2;
    table['Lv'] = 293.2;
    table['Ts'] = 294.2;
    table['Og'] = 294.2;
    memset(tmp, 'A', sizeof(tmp));
}
int main(int argc, char const *argv[])
{
    init();
    int case_count;
    int len;
    scanf("%d", &case_count);
    getchar();
    for (int i = 0; i < case_count; i++)
    {
        int pos = 0;
        double ans = 0;
        gets(tmp);
        len = strlen(tmp);
        while (pos < len)
        {
            if (islower(tmp[pos + 1]))
            {
                if (isdigit(tmp[pos + 2]))
                {
                    ans += atoi(tmp + pos + 2) * table[tmp[pos] * 256 + tmp[pos + 1]];
                    pos++;
                    while (!isupper(tmp[pos]))
                        pos++;
                }
                else
                {
                    ans += table[tmp[pos] * 256 + tmp[pos + 1]];
                    pos++;
                    while (!isupper(tmp[pos]))
                        pos++;
                }
            }
            else if (isdigit(tmp[pos + 1]))
            {
                ans += atoi(tmp + pos + 1) * table[tmp[pos]];
                pos++;
                while (!isupper(tmp[pos]))
                    pos++;
            }
            else
            {
                ans += table[tmp[pos]];
                pos++;
                while (!isupper(tmp[pos]))
                    pos++;
            }
        }
        printf("%lf\n", ans);
    }
    return 0;
}
