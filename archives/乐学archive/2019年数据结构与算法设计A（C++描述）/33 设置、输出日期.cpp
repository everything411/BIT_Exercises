#include <iostream>
using namespace std;
class Date
{
  private:
    int year, month, day;

  public:
    void SetDate(int y, int m, int d);
    int GetDay();
    int GetMonth();
    int GetYear();
    void ShowDate();
};
void Date::SetDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
int Date::GetDay()
{
    return day;
}
int Date::GetMonth()
{
    return month;
}
int Date::GetYear()
{
    return year;
}
void Date::ShowDate()
{
    cout << year << '/' << month << '/' << day << '/' << endl;
}
int main(int argc, char const *argv[])
{
    Date date;
    int year, month, day;
    cin >> year >> month >> day;
    date.SetDate(year, month, day);
    date.ShowDate();
    return 0;
}
