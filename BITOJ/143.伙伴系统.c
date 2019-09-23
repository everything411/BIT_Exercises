#include <stdio.h>
int memory[11];
const int size_tab[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int find_mem(int size)
{
    for (int i = 0; i < 11; i++)
        if (size <= size_tab[i] && memory[i])
            return i;
    return -1;
}
void _free(int size)
{
    for (int i = 0; i < 11; i++)
        memory[i] += (size >> i) & 1;
}
int _alloc(int size)
{
    int index = find_mem(size);
    if (index == -1)
    {
        return -1;
    }
    else
    {
        memory[index]--;
        _free(size_tab[index] - size);
        return 0;
    }
}
void print(void)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", memory[i]);
    printf("%d \n", memory[10]);
}
int main(int argc, char const *argv[])
{
    char command[64];
    int case_count;
    int mem_size;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        scanf("%s%d", command, &mem_size);
        switch (*command)
        {
        case 'f':
            _free(mem_size);
            print();
            break;
        case 'a':
            if (!_alloc(mem_size))
                print();
            else
                puts("ERROR!");
            break;
        default:
            //puts("Wrong command!");
            break;
        }
    }
    return 0;
}