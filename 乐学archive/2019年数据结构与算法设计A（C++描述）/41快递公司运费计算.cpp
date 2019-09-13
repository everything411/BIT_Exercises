#include <iostream>
using namespace std;
int price_table[4][6][3] = {
    {{10, 14, 18}, {15, 19, 23}, {15, 19, 23}, {15, 21, 27}, {15, 21, 27}, {15, 25, 35}},
    {{12, 14, 16}, {20, 30, 40}, {20, 28, 36}, {20, 34, 46}, {20, 32, 44}, {20, 34, 48}},
    {{26, 38, 50}, {26, 38, 50}, {26, 38, 50}, {29, 47, 65}, {35, 65, 95}, {38, 66, 95}},
    {{10, 18, 26}, {10, 18, 26}, {12, 24, 36}, {12, 22, 32}, {15, 27, 39}, {18, 33, 48}}};
const char *city_name(int city_id)
{
    switch (city_id)
    {
    case 1:
        return (const char *)"天津";
    case 2:
        return (const char *)"上海";
    case 3:
        return (const char *)"太原";
    case 4:
        return (const char *)"广州";
    case 5:
        return (const char *)"昆明";
    case 6:
        return (const char *)"新疆";
    default:
        return (const char *)"undefined city";
    }
}
const char *company_name(int express_id)
{
    switch (express_id)
    {
    case 1:
        return (const char *)"E通宝";
    case 2:
        return (const char *)"顺风";
    case 3:
        return (const char *)"EMS";
    case 4:
        return (const char *)"圆通";
    default:
        return (const char *)"undefined company";
    }
}
int get_price(int city_id, int express_id, int weight)
{
    return price_table[express_id - 1][city_id - 1][weight - 1];
}

struct express_com
{
  protected:
    int city_id;
    int count;     //城市编号、货物个数
    double weight; //货物重量
  public:
    void init(int __no, int __num, double __weight)
    {
        city_id = __no;
        count = __num;
        weight = __weight;
    }
    virtual double cost(void) = 0; //计算运费函数
    virtual void print(void) = 0;  //输出全部信息
    void print_goods(void)         //输出货物个数、货物重量信息
    {
        cout << "重量：" << weight << "KG" << endl;
        cout << "货物个数：" << count << endl;
    }
    void __print(int city_id, int express_id, double weight, double price)
    {
        cout << "公司名称：" << company_name(express_id) << endl;
        cout << "目的地：" << city_name(city_id) << endl;
        print_goods();
        cout << "单价：" << price << endl;
        cout << "总运费：" << price * count << endl;
    }
};
struct eub : express_com
{
    static const int express_id = 1;
    double cost(void)
    {
        return get_price(city_id, express_id, weight);
    }
    void print(void)
    {
        __print(city_id, express_id, weight, cost());
    }
};
struct sf : express_com
{
    static const int express_id = 2;
    double cost(void)
    {
        return get_price(city_id, express_id, weight);
    }
    void print(void)
    {
        __print(city_id, express_id, weight, cost());
    }
};
struct ems : express_com
{
    static const int express_id = 3;
    double cost(void)
    {
        return get_price(city_id, express_id, weight);
    }
    void print(void)
    {
        __print(city_id, express_id, weight, cost());
    }
};
struct yto : express_com
{
    static const int express_id = 4;
    double cost(void)
    {
        return get_price(city_id, express_id, weight);
    }
    void print(void)
    {
        __print(city_id, express_id, weight, cost());
    }
};

int main(void)
{
    int express_id, city_id, goods_count;
    double weight;
    express_com *companys[4] = {new eub, new sf, new ems, new yto};
    cin >> express_id >> city_id >> goods_count >> weight;
    companys[express_id - 1]->init(city_id, goods_count, weight);
    companys[express_id - 1]->print();
    return 0;
}
