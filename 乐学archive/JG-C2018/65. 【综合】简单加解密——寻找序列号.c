#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MaxPass 66         // 最多66段密文
#define NumbPwdTable 5     // 密码表的份数
#define SizePwdTable 0x210 // 每份密码表占用字节数

typedef struct // 密码表结构: 编移(4字节),密文长度(2字节),钥匙(1字节)。 结构体长度此处须为 4的倍数
{
    unsigned int Offset;
    unsigned short int Size;
    unsigned char Key;
    char cJiangYou;
} PassStru_t; // cJiangYou打酱油

#define MsgErr "Wrong Key!"
#define MsgSn "Serial No.: "
#define MsgMD9 "MD9: "

int main(int argc, char const *argv[])
{
    char name[128];
    int number;
    char *sn_pos, *m9_pos;
    PassStru_t(*PasswdTable)[MaxPass] = (PassStru_t(*)[MaxPass])malloc(NumbPwdTable * MaxPass * sizeof(PassStru_t));
    scanf("%s%d", name, &number);
    FILE *PassFile = fopen(name, "rb");
    fread(PasswdTable, SizePwdTable, NumbPwdTable, PassFile);
    for (int i = 0; i < NumbPwdTable; i++)
    {
        int offset = PasswdTable[i][number - 1].Offset;
        int size = PasswdTable[i][number - 1].Size;
        int key = PasswdTable[i][number - 1].Key;
        fseek(PassFile, offset, SEEK_SET);
        char *buffer = (char *)calloc(size + 1, sizeof(char));
        fread(buffer, size, sizeof(char), PassFile);
        for (int i = 0; i < size; i++)
            buffer[i] = (buffer[i] + key) % 0x100U;
        if (strncmp(buffer, MsgErr, 10))
        {
            fputs(buffer, stderr);
            sn_pos = strstr(buffer, MsgSn) + sizeof(MsgSn) - 1;
            m9_pos = strstr(buffer, MsgMD9) + sizeof(MsgMD9) - 1;
            printf("XH: %02d\n"
                   "SN: %.19s\n"
                   "M9: %.32s\n",
                   number, sn_pos, m9_pos);
            free(buffer);
            break;
        }
        free(buffer);
    }
    free(PasswdTable);
    fclose(PassFile);
    return 0;
}
