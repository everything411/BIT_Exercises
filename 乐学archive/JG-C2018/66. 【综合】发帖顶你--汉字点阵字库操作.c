#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 94
#define MASK 0x1
int main(int argc, char const *argv[])
{
    int bit_size, high_code, low_code;
    int byte, line_byte;
    char background, foreground;
    char file_name[64];
    unsigned char bit_operate_buffer;
    scanf("%d,%s%2d%2d,%c,%c", &bit_size, file_name, &high_code, &low_code, &background, &foreground);
    //convert from row&col number to row&col offset
    high_code -= 16;
    low_code -= 1;
    byte = bit_size * bit_size / 8;
    line_byte = bit_size / 8;
    unsigned char matrix[byte];
    char *buffer = (char *)calloc(bit_size * (bit_size + 1) + 1, sizeof(char));
    int count = 0;
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        perror(argv[0]);
        return 1;
    }
    fseek(fp, (high_code * MAX_SIZE + low_code) * byte, SEEK_SET);
    fprintf(stderr, "row %d col %d: fseek() to offset %d\n", high_code + 16, low_code + 1, (high_code * MAX_SIZE + low_code) * byte);
    fread(matrix, sizeof(char), byte, fp);
    fprintf(stderr, "read %d byte...\n", byte);
    fprintf(stderr, "character size %d byte\n", line_byte);
    for (int i = 0; i < bit_size; i++) //column loop
    {
        for (int j = 0; j < line_byte; j++) //row byte size read loop
        {
            bit_operate_buffer = matrix[i * line_byte + j];
            for (int k = 0; k < 8; k++)
            {
                if ((bit_operate_buffer >> (7 - k)) & MASK)
                {
                    buffer[count++] = foreground;
                }
                else
                {
                    buffer[count++] = background;
                }
            }
        }
        buffer[count++] = '\n';
    }
    fputs(buffer, stdout);
    fprintf(stderr, "write %d byte to stdout\n", count);
    free(buffer);
    fclose(fp);
    return 0;
}
