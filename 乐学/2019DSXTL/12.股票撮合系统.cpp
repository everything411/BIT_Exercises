#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <map>
using namespace std;
int id_seed(void)
{
    static int id = 1;
    return id++;
}
struct order
{
    int id;
    int stockid;
    double price;
    int quantity;
    char type;
};
bool operator>(const order &a, const order &b)
{
    if (a.price != b.price)
    {
        return a.price > b.price;
    }
    else
    {
        return a.id > b.id;
    }
    // return a.price > b.price;
}
bool operator<(const order &a, const order &b)
{
    if (a.price != b.price)
    {
        return a.price < b.price;
    }
    else
    {
        return a.id > b.id;
    }
}
typedef priority_queue<order, vector<struct order>, less<struct order>> buy_queue_t;
typedef priority_queue<order, vector<struct order>, greater<struct order>> sell_queue_t;

map<int, buy_queue_t> q_buy;
map<int, sell_queue_t> q_sell;
map<int, struct order> order_id;
void do_insert_and_deal()
{
    struct order order;
    order.id = id_seed();
    scanf("%d%lf%d %c", &order.stockid, &order.price, &order.quantity, &order.type);
    printf("orderid: %04d\n", order.id);
    if (order.type == 's')
    {
        struct order buy, sell;
        int stockid = order.stockid;
        sell = order;
        if (q_buy.find(stockid) != q_buy.end())
        {
            auto buyq = q_buy[stockid];
            while (!buyq.empty() && sell.quantity >= 0)
            {
                buy = buyq.top();
                if (sell.price <= buy.price)
                {
                    int m = min(sell.quantity, buy.quantity);
                    sell.quantity -= m;
                    buy.quantity -= m;
                    q_buy[stockid].pop();
                    buyq.pop();
                    if (buy.quantity != 0)
                    {
                        q_buy[stockid].push(buy);
                        // break;
                    }
                    else
                    {
                        order_id.erase(buy.id);
                    }
                    printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",
                           (sell.price + buy.price) / 2, m, sell.id, buy.id);
                }
                else
                {
                    break;
                }
                if (sell.quantity == 0)
                {
                    break;
                }
            }
        }
        if (sell.quantity != 0)
        {
            order_id.emplace(order.id, sell);
            q_sell[order.stockid].push(sell);
        }
    }
    else
    {
        struct order buy, sell;
        int stockid = order.stockid;
        buy = order;
        if (q_sell.find(stockid) != q_sell.end())
        {
            auto sellq = q_sell[stockid];
            while (!sellq.empty() && buy.quantity >= 0)
            {
                sell = sellq.top();
                if (sell.price <= buy.price)
                {
                    int m = min(sell.quantity, buy.quantity);
                    sell.quantity -= m;
                    buy.quantity -= m;
                    q_sell[stockid].pop();
                    sellq.pop();
                    if (sell.quantity != 0)
                    {
                        q_sell[stockid].push(sell);
                        // break;
                    }
                    else
                    {
                        order_id.erase(sell.id);
                    }
                    printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",
                           (sell.price + buy.price) / 2, m, buy.id, sell.id);
                }
                else
                {
                    break;
                }
                if (buy.quantity == 0)
                {
                    break;
                }
            }
        }
        if (buy.quantity != 0)
        {
            order_id.emplace(order.id, buy);
            q_buy[order.stockid].push(buy);
        }
    }
}
void do_query()
{
    int id;
    scanf("%d", &id);
    puts("buy orders:");
    if (q_buy.find(id) != q_buy.end())
    {
        auto tmpqueue = q_buy[id];
        while (!tmpqueue.empty())
        {
            auto tmporder = tmpqueue.top();
            tmpqueue.pop();
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",
                   tmporder.id, tmporder.stockid, tmporder.price, tmporder.quantity, tmporder.type);
        }
    }
    puts("sell orders:");
    if (q_sell.find(id) != q_sell.end())
    {
        auto tmpqueue = q_sell[id];
        while (!tmpqueue.empty())
        {
            auto tmporder = tmpqueue.top();
            tmpqueue.pop();
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",
                   tmporder.id, tmporder.stockid, tmporder.price, tmporder.quantity, tmporder.type);
        }
    }
}
void do_delete()
{
    int id;
    scanf("%d", &id);
    if (order_id.find(id) != order_id.end())
    {
        auto tmporder = order_id[id];
        int stockid = tmporder.stockid;
        if (tmporder.type == 's')
        {
            auto tmpqueue = q_sell[stockid];
            decltype(tmpqueue) tmpqueue2;
            while (!tmpqueue.empty())
            {
                auto tmporder2 = tmpqueue.top();
                tmpqueue.pop();
                if (tmporder2.id != id)
                {
                    tmpqueue2.push(tmporder2);
                }
                else
                {
                    tmporder = tmporder2;
                }
            }
            q_sell[stockid] = tmpqueue2;
        }
        else
        {
            auto tmpqueue = q_buy[stockid];
            decltype(tmpqueue) tmpqueue2;
            while (!tmpqueue.empty())
            {
                auto tmporder2 = tmpqueue.top();
                tmpqueue.pop();
                if (tmporder2.id != id)
                {
                    tmpqueue2.push(tmporder2);
                }
                else
                {
                    tmporder = tmporder2;
                }
            }
            q_buy[stockid] = tmpqueue2;
        }
        order_id.erase(id);
        printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",
               tmporder.id, tmporder.stockid, tmporder.price, tmporder.quantity, tmporder.type);
    }
    else
    {
        // exit(127);
        puts("not found");
    }
}
int main(int argc, char const *argv[])
{
    int cmd;
    while (~scanf("%d", &cmd) && cmd != 0)
    {
        switch (cmd)
        {
        case 1:
            do_insert_and_deal();
            break;
        case 2:
            do_query();
            break;
        case 3:
            do_delete();
            break;
        default:
            fputs("go die!\n", stderr);
            break;
        }
    }
    return 0;
}
