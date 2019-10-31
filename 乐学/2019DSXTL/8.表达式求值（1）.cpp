#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
using namespace std;
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
int calc_expression(char *expression);
int quickpow(int base, int power);
int expression_state;
int main(int argc, char const *argv[])
{
    int t;
    int ans;
    char exp[100];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        memset(exp, 0, sizeof(exp));
        exp[0] = '#';
        scanf("%s", exp + 1);
        strcat(exp, "#");
        ans = calc_expression(exp);
        switch (expression_state)
        {
        case OK:
            printf("%d\n", ans);
            break;
        case ERROR:
            puts("error.");
            break;
        case DIVZERO:
            puts("Divide 0.");
            break;
        default:
            break;
        }
    }
    return 0;
}

int calc_expression(char *expression)
{
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
        if (*pos == '(' && isdigit(*(pos - 1)))
        {
            fprintf(stderr, "( after number!\n");
            expression_state = ERROR;
            return 0;
        }
        if (*pos == ')' && isdigit(*(pos + 1)))
        {
            fprintf(stderr, "number after )!\n");
            expression_state = ERROR;
            return 0;
        }
        if (opcode_index(*pos) == -1 || (opcode_index(*(pos - 1)) != -1 && (*pos == '-' && isdigit(*(pos + 1)))))
        {
            nxt[0] = *pos;
            strcat(opchar_buffer, nxt);
            pos++;
            if (opcode_index(*pos) != -1)
            {
                Data = strtol(opchar_buffer, NULL, 10);
                operand_stack.push(Data);
                memset(opchar_buffer, 0, sizeof(opchar_buffer));
            }
        }
        else
        {
            if (opcode_stack.empty())
            {
                fprintf(stderr, "operator stack is empty!\n");
                expression_state = ERROR;
                return 0;
            }
            switch (get_prior(opcode_stack.top(), *pos))
            {
            case '<':
                opcode_stack.push(*pos);
                pos++;
                break;
            case '=':
                if (opcode_stack.empty())
                {
                    fprintf(stderr, "operator stack is empty!\n");
                    expression_state = ERROR;
                    return 0;
                }
                opcode_stack.pop();
                pos++;
                break;
            case '>':
                if (opcode_stack.empty())
                {
                    fprintf(stderr, "operator stack is empty!\n");
                    expression_state = ERROR;
                    return 0;
                }
                opcode = opcode_stack.top();
                opcode_stack.pop();
                if (operand_stack.empty())
                {
                    fprintf(stderr, "operand stack is empty!\n");
                    expression_state = ERROR;
                    return 0;
                }
                b = operand_stack.top();
                operand_stack.pop();
                if (operand_stack.empty())
                {
                    fprintf(stderr, "operand stack is empty!\n");
                    expression_state = ERROR;
                    return 0;
                }
                a = operand_stack.top();
                operand_stack.pop();
                tmp = do_calc(a, opcode, b);
                if (expression_state != OK)
                {
                    return 0;
                }
                operand_stack.push(tmp);
                break;
            case ' ':
                fprintf(stderr, "invaild opcode %c and %c!\n", opcode_stack.top(), *pos);
                expression_state = ERROR;
                return 0;
            }
        }
        if (opcode_stack.empty())
        {
            fprintf(stderr, "operator stack is empty!\n");
            expression_state = ERROR;
            return 0;
        }
    }
    if (operand_stack.size() != 1)
    {
        fprintf(stderr, "stack size != 1\n");
        expression_state = ERROR;
        return 0;
    }
    return operand_stack.top();
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
        if (b < 0)
        {
            fprintf(stderr, "negative power!\n");
            expression_state = ERROR;
            return 0;
        }
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