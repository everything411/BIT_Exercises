#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
using namespace std;
extern "C" char *gets(char *);
#define OK 0
#define ERROR 1
#define DIVZERO 2
#define OPSETSIZE 9
char prior_table[OPSETSIZE][OPSETSIZE] = {
    /*+    -    *    /    (    )    #    ^    % */
    {'>', '>', '<', '<', '<', '>', '>', '<', '<'},  // +
    {'>', '>', '<', '<', '<', '>', '>', '<', '<'},  // -
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},  // *
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},  // /
    {'<', '<', '<', '<', '<', '=', ' ', '<', '<'},  // (
    {'>', '>', '>', '>', ' ', '>', '>', '>', '>'},  // )
    {'<', '<', '<', '<', '<', ' ', '=', '<', '<'},  // #
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},  // ^
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'}}; // %
char OPSET[OPSETSIZE] = {'+', '-', '*', '/', '(', ')', '#', '^', '%'};
int opcode_index(char op);
int do_calc(int a, char opcode, int b);
char get_prior(char Aop, char Bop);
void calc_expression(char *expression);
int quickpow(int base, int power);
int expression_state;
map<string, int> result;
int main(int argc, char const *argv[])
{
    // int ans;
    char exp[100];
    while (gets(exp) && strcmp(exp, "end"))
    {
        calc_expression(exp);
        memset(exp, 0, sizeof(exp));
    }
    return 0;
}

void calc_expression(char *expression)
{
    // fprintf(stderr, "calc_expression(): %s\n", expression);
    if (*expression == '?')
    {
        string iden = expression + 2;
        if (result.find(iden) != result.end())
        {
            printf("%s=%d\n", iden.data(), result[iden]);
        }
        return;
    }
    char *op_equ = strchr(expression, '=');
    *op_equ = 0;
    string identifier = expression;
    op_equ[-1] = 0;
    op_equ[0] = '#';
    expression = op_equ;
    strcat(expression, "#");
    // swap(identifier, expression);
    expression_state = OK;
    stack<char> opcode_stack;
    stack<int> operand_stack;
    int tmp;
    char opchar_buffer[32] = {0};
    int Data, a, b;
    char opcode;
    char *pos;
    char nxt[2] = {0};
    pos = expression;
    opcode_stack.push(*pos++); // #
    while (*pos != '#' || opcode_stack.top() != '#')
    {
        if (opcode_index(*pos) == -1 || (opcode_index(*(pos - 1)) != -1 && (*pos == '-' && isdigit(*(pos + 1)))))
        {
            nxt[0] = *pos;
            strcat(opchar_buffer, nxt);
            pos++;
            if (opcode_index(*pos) != -1)
            {
                char *endptr;
                Data = strtol(opchar_buffer, &endptr, 10);
                if (opchar_buffer == endptr)
                {
                    Data = result[opchar_buffer];
                    fprintf(stderr, "map: %s == %d\n", opchar_buffer, Data);
                }
                operand_stack.push(Data);
                memset(opchar_buffer, 0, sizeof(opchar_buffer));
            }
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
                b = operand_stack.top();
                operand_stack.pop();
                a = operand_stack.top();
                operand_stack.pop();
                tmp = do_calc(a, opcode, b);
                if (expression_state == DIVZERO)
                {
                    puts("Divide 0.");
                    return;
                }
                operand_stack.push(tmp);
                break;
            case ' ':
                return;
            }
        }
    }
    if (result.find(identifier) != result.end())
    {
        result[identifier] = operand_stack.top();
    }
    else
    {
        result.emplace(identifier, operand_stack.top());
    }
    return;
}
int do_calc(int a, char opcode, int b)
{
    switch (opcode)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            fprintf(stderr, "div by zero!\n");
            expression_state = DIVZERO;
            return 0;
        }
        else
        {
            return a / b;
        }
    case '%':
        if (b == 0)
        {
            fprintf(stderr, "div by zero!\n");
            expression_state = DIVZERO;
            return 0;
        }
        else
        {
            return a % b;
        }
    case '^':
        return quickpow(a, b);
    default:
        return 0;
    }
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
int quickpow(int base, int power)
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
            ans *= base;
        base *= base;
        power >>= 1;
    }
    return ans;
}
