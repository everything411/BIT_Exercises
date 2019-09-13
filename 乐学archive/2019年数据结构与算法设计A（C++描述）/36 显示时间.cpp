#include <iostream>
using namespace std;
class Time
{
  private:
    int hour;
    int minute;
    int second;

  public:
    void setTime(void);
    void print(void);
    Time();
};

Time::Time()
{
    hour = minute = second = 0;
}

void Time::setTime(void)
{
    cin >> hour >> minute >> second;
    if (hour > 23 || hour < 0)
    {
        hour = 0;
    }
    if (minute > 59 || minute < 0)
    {
        minute = 0;
    }
    if (second > 59 || second < 0)
    {
        second = 0;
    }
}
void Time::print(void)
{
    cout << hour << ':' << minute << ':' << second << endl;
}
int main(void)
{
    Time demo_time;
    demo_time.setTime();
    demo_time.print();
    return 0;
}