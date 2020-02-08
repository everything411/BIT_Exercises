#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
using namespace std;
extern "C" char *gets(char *);
#define OPSETSIZE 8

char prior_table[OPSETSIZE][OPSETSIZE] = {
    /*-    +    &    |    (    )    #    !    */
    {'>', '>', '<', '<', '<', '>', '>', '<'},  // -
    {'<', '>', '<', '<', '<', '>', '>', '<'},  // +
    {'>', '>', '>', '>', '<', '>', '>', '<'},  // &
    {'>', '>', '<', '>', '<', '>', '>', '<'},  // |
    {'<', '<', '<', '<', '<', '=', ' ', '<'},  // (
    {'>', '>', '>', '>', ' ', '>', '>', '>'},  // )
    {'<', '<', '<', '<', '<', ' ', '=', '<'},  // #
    {'>', '>', '>', '>', '<', '>', '>', '<'}}; // !
char OPSET[OPSETSIZE] = {'-', '+', '&', '|', '(', ')', '#', '!'};
int opcode_index(char op);
int do_calc(int a, char opcode, int b);
char get_prior(char Aop, char Bop);
int calc_expression(char *expression);
void init_val(unsigned long long val);
char expression[1000];
char expression2[1000];
int char_val[128];
char alpha[128];
int value[16384];
int main(int argc, char const *argv[])
{
    int count = 0;
    expression[0] = '#';
    gets(expression + 1);
    strcat(expression, "#");
    int len = strlen(expression);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(expression[i]))
        {
            char_val[expression[i]] = 1;
        }
    }
    for (int i = 0; i < 128; i++)
    {
        if (char_val[i])
        {
            alpha[count++] = i;
        }
    }
    int v = 1 << count;
    for (int i = 0; i < v; i++)
    {
        init_val(i);
        value[i] = calc_expression(expression2);
    }
    int tcount, fcount;
    tcount = fcount = 0;
    for (int i = 0; i < v; i++)
    {
        if (value[i])
        {
            tcount++;
        }
        else
        {
            fcount++;
        }
    }

    int t, f;
    t = f = 0;
    if (fcount == v)
    {
        printf("0");
    }
    else
    {
        for (int i = 0; i < v; i++)
        {
            if (value[i])
            {
                if (t == tcount - 1)
                {
                    printf("m%d", i);
                }
                else
                {
                    printf("m%d ∨ ", i);
                }
                t++;
            }
        }
    }
    printf(" ; ");
    if (tcount == v)
    {
        printf("1");
    }
    else
    {
        for (int i = 0; i < v; i++)
        {
            if (!value[i])
            {
                if (f == fcount - 1)
                {
                    printf("M%d", i);
                }
                else
                {
                    printf("M%d ∧ ", i);
                }
                f++;
            }
        }
    }
    printf("\n");
    return 0;
}
void init_val(unsigned long long val)
{
    memset(char_val, 0, sizeof(char_val));
    memset(expression2, 0, sizeof(expression2));
    int len = strlen(alpha);
    for (int i = 0; i < len; i++)
    {
        char_val[alpha[i]] = ((val >> (len - i - 1)) & 1) + '0';
    }
    len = strlen(expression);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(expression[i]))
        {
            expression2[i] = char_val[expression[i]];
        }
        else
        {
            expression2[i] = expression[i];
        }
    }
}
int calc_expression(char *expression)
{
    // fprintf(stderr, "calc_expression(): %s\n", expression);
    stack<char> opcode_stack;
    stack<int> operand_stack;
    int tmp;
    int a, b;
    char opcode;
    char *pos;
    pos = expression;
    opcode_stack.push(*pos++); // #
    while (*pos != '#' || opcode_stack.top() != '#')
    {
        if (isdigit(*pos))
        {
            operand_stack.push(*pos - '0');
            pos++;
        }
        else
        {
            switch (get_prior(opcode_stack.top(), *pos))
            {
            case '<':
                opcode_stack.push(*pos);
                pos++;
                break;
            case '=':
                opcode_stack.pop();
                pos++;
                break;
            case '>':
                opcode = opcode_stack.top();
                opcode_stack.pop();
                if (opcode == '!')
                {
                    tmp = !operand_stack.top();
                    operand_stack.pop();
                    operand_stack.push(tmp);
                    break;
                }
                b = operand_stack.top();
                operand_stack.pop();
                a = operand_stack.top();
                operand_stack.pop();
                tmp = do_calc(a, opcode, b);
                if (!opcode_stack.empty() && opcode_stack.top() == '!')
                {
                    opcode_stack.pop();
                    tmp = !tmp;
                }
                operand_stack.push(tmp);
                break;
            case ' ':
                return -1;
            }
        }
    }
    return operand_stack.top();
}
int opcode_index(char op)
{
    for (int i = 0; i < OPSETSIZE; i++)
    {
        if (op == OPSET[i])
            return i;
    }
    return -1;
}

char get_prior(char Aop, char Bop)
{
    return prior_table[opcode_index(Aop)][opcode_index(Bop)];
}

bool _negation[2] = {true, false};
bool _implication[2][2] = {true, true, false, true};
bool _conjunction[2][2] = {false, false, false, true};
bool _disjunction[2][2] = {false, true, true, true};
bool _equivalence[2][2] = {true, false, false, true};
int do_calc(int a, char opcode, int b = 0)
{
    switch (opcode)
    {
    case '!':
        return _negation[a];
    case '-':
        return _implication[a][b];
    case '&':
        return _conjunction[a][b];
    case '|':
        return _disjunction[a][b];
    case '+':
        return _equivalence[a][b];
    default:
        fputs("error operator!\n", stderr);
        return 0;
    }
}