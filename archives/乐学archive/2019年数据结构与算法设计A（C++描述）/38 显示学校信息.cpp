#include <iostream>
#include <cstring>
using namespace std;
class person
{
  public:
    char name[100];
    int id;
    person(void)
    {
        ;
    }
    person(int n, char *s)
    {
        id = n;
        strncpy(name, s, 100);
    }
    void print(void)
    {
        printf("Personinformation:\nName:%s\nNumber:%d\n", name, id);
    }
};
class student : person
{
    char subject[100];
    double score;

  public:
    student(int n, char *s, char *s_2, double r)
    {
        id = n;
        strncpy(name, s, 100);
        strncpy(subject, s_2, 100);
        score = r;
    }
    void print(void)
    {
        printf("Studentinformation:\nName:%s\nNumber:%d\nCourse:%s\nGrade:", name, id, subject);
        cout << score << endl;
    }
};

class teacher : person
{
  public:
    char pro[100];
    int paper;
    teacher(int n, char *s, char *s_2, int r)
    {
        id = n;
        strncpy(name, s, 100);
        strncpy(pro, s_2, 100);
        paper = r;
    }
    void print(void)
    {
        printf("Teacherinformation:\nName:%s\nNumber:%d\npro:%s\npaper:%d\n", name, id, pro, paper);
        // cout << score << endl;
    }
};

int main(void)
{
    char name[100];
    int id;
    char s2[100];
    double score;
    int paper;
    scanf("%s%d%s%lf", name, &id, s2, &score);
    student demo_stu(id, name, s2, score);
    scanf("%s%d%s%d", name, &id, s2, &paper);
    teacher demo_tea(id, name, s2, paper);
    demo_stu.print();
    putchar('\n');
    demo_tea.print();
    return 0;
}
