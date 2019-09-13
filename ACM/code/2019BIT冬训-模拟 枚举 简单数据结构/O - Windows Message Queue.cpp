#include <iostream>
#include <string>
#include <queue>
#include <functional>
using namespace std;
struct msg_t
{
    string msg;
    int para;
    int pri;
    int order;
};
bool operator<(msg_t a, msg_t b)
{
    if (a.pri == b.pri)
    {
        return a.order > b.order;
    }
    else
    {
        return a.pri > b.pri;
    }
}
int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<msg_t> msg_que;
    char command[10];
    int count = 0;
    while (cin >> command)
    {
        switch (*command)
        {
        case 'P':
        {
            msg_t tmp_msg;
            cin >> tmp_msg.msg >> tmp_msg.para >> tmp_msg.pri;
            tmp_msg.order = count++;
            msg_que.push(tmp_msg);
            break;
        }
        case 'G':
        {
            if (msg_que.empty())
            {
                cout << "EMPTY QUEUE!\n";
            }
            else
            {
                const msg_t &msg = msg_que.top();
                cout << msg.msg << ' ' << msg.para << '\n';
                msg_que.pop();
            }
        }
        break;
        }
    }

    return 0;
}
