#include <iostream>
using namespace std;
// 书号、书名、出版社和定价
struct book
{
    int id;
    char name[100];
    char publisher[100];
    double price;
    void book_in(void)
    {
        scanf("%d%s%s%lf", &id, name, publisher, &price);
    }
    void book_out(void)
    {
        printf("Num:%d\nBookName:%s\nBookConcern:%s\nPrice:", id, name, publisher);
        cout << price << endl;
    }
    // book(/* args */);
    // ~book();
};
// 姓名、年龄和写作时间
struct author
{
    char name[100];
    int age;
    int year;
    int month;
    int day;
    void author_in(void)
    {
        scanf("%s%d%d%d%d", name, &age, &year, &month, &day);
    }
    void author_out(void)
    {
        printf("AuthorName:%s\nAuthorAge:%d\nPrintTime:%d-%d-%d\n", name, age, year, month, day);
        // cout << price << endl;
    }
    // author(/* args */);
    // ~author();
};
// 书籍系统名称，及一个可以显示系统名称、书名、作者、作者年龄、出版社和定价等数据的函数
struct book_sys : book, author
{
    char sys_name[100];
    void sys_in(void)
    {
        scanf("%s", sys_name);
        book_in();
        author_in();
    }
    void sys_out(void)
    {
        printf("SysName:%s\n", sys_name);
        book_out();
        author_out();
    }
    // book_sys(/* args */);
    // ~book_sys();
};

int main(void)
{
    book_sys demo;
    demo.sys_in();
    demo.sys_out();
    return 0;
}
