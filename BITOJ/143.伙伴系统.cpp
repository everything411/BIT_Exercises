#include <iostream>
using namespace std;
int memory[11];
int memsize[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
void _free(int size)
{
    for (int i = 0; i < 11; i++)
        memory[i] += (size >> i) & 1;
}
int _find(int size)
{
    for (int i = 0; i < 11; i++)
        if (memory[i] != 0 && memsize[i] >= size)
            return i;
    return -1;
}
bool _alloc(int size)
{
    int index;
    if ((index = _find(size)) == -1)
    {
        return false;
    }
    else
    {
        memory[index]--;
        _free(memsize[index] - size);
        return true;
    }
}
void _print(void)
{
    for (int i = 0; i < 11; i++)
        printf("%d%c", memory[i], i == 10 ? '\n' : ' ');
}
void _error(void)
{
    puts("ERROR!");
}
int main(int argc, char const *argv[])
{
    int op_count;
    int size;
    char command[32];
    scanf("%d", &op_count);
    for (int i = 0; i < op_count; i++)
    {
        scanf("%s%d", command, &size);
        switch (command[0])
        {
        case 'a':
        case 'A':
            if (_alloc(size) == true)
                _print();
            else
                _error();
            break;
        case 'f':
        case 'F':
            _free(size);
            _print();
        default:
            break;
        }
    }
    return 0;
}
