#include <iostream>
#include <vector>
using namespace std;
class my_set_t
{
  private:
    vector<int> numbers;

  public:
    my_set_t operator+(my_set_t &b)
    {
        my_set_t tmp = *this;
        for (int i = 0; i < b.numbers.size(); i++)
        {
            for (int j = 0; j < tmp.numbers.size(); j++)
            {
                if (tmp.numbers[j] == b.numbers[i])
                {
                    goto out_for;
                }
            }
            tmp.numbers.push_back(b.numbers[i]);
        out_for:;
        }

        return tmp;
    }
    my_set_t operator-(my_set_t &b)
    {
        my_set_t tmp = *this;
        for (int i = 0; i < b.numbers.size(); i++)
        {
            for (vector<int>::iterator j = tmp.numbers.begin(); j != tmp.numbers.end(); j++)
            {
                if (*j == b.numbers[i])
                {
                    tmp.numbers.erase(j);
                    break;
                }
            }
        }
        return tmp;
    }
    void print(void)
    {
        if (this->numbers.empty())
            cout << endl;
        else
            for (int i = 0; i < numbers.size(); i++)
                cout << numbers[i] << (i == numbers.size() - 1 ? '\n' : ' ');
    }
    void read(void)
    {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
};
int main(void)
{
    my_set_t set1, set2;
    int a_size, b_size;
    cin >> a_size;
    for (int i = 0; i < a_size; i++)
    {
        set1.read();
    }
    cin >> b_size;
    for (int i = 0; i < b_size; i++)
    {
        set2.read();
    }
    my_set_t add = set1 + set2;
    my_set_t sub = set1 - set2;
    cout << "int1+int2=";
    add.print();
    cout << "int1-int2=";
    sub.print();
    return 0;
}