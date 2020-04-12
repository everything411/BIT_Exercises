#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class counter_t
{
  private:
    int count;

  public:
    counter_t();
    void countWord(string &str);
    void show(void);
};

counter_t::counter_t()
{
    count = 0;
}
void counter_t::countWord(string &str)
{
    int len = str.length();
    bool inword = false;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(str[i]) && !inword)
        {
            inword = true;
            count++;
        }
        else if (!isalpha(str[i]) && inword)
        {
            inword = false;
        }
    }
}
void counter_t::show(void)
{
    cout << "Words=" << count << endl;
}
int main(int argc, char const *argv[])
{
    counter_t counter;
    string buf;
    getline(cin, buf);
    counter.countWord(buf);
    counter.show();
    return 0;
}
