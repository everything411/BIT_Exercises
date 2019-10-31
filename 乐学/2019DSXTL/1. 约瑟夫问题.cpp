#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k, m;
    scanf("%d,%d,%d", &n, &k, &m);
    if (n < 1 || k < 1 || m < 1)
    {
        puts("n,m,k must bigger than 0.");
        return 0;
    }
    if (k > n)
    {
        puts("k should not bigger than n.");
        return 0;
    }
    vector<int> people;
    vector<int> answer;
    for (int i = 1; i <= n; i++)
    {
        people.push_back(i);
    }
    int curr_pos = k - 1;
    for (int i = 1; true; i++)
    {
        if (i % m == 0)
        {
            answer.push_back(people[curr_pos]);
            people.erase(people.begin() + curr_pos);
        }
        else
        {
            if (people.empty())
            {
                break;
            }
            curr_pos = (curr_pos + 1) % people.size();
        }
    }
    for (size_t i = 0; i < answer.size(); i++)
    {
        printf("%d%c", answer[i], ((((i + 1) % 10 == 0) || (i == answer.size() - 1)) ? '\n' : ' '));
    }

    return 0;
}
