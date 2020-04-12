#include <iostream>
using namespace std;
struct shape
{
    double x;
    double y;
    shape(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    virtual double get_area(void) = 0;
    virtual void print_area(void) = 0;
};
struct triangle : shape
{
    triangle(double a, double h) : shape(a, h)
    {
        ;
    }
    double get_area(void)
    {
        return x * y / 2;
    }
    void print_area(void)
    {
        cout << "Triangle Area=" << get_area() << endl;
    }
};
struct rectangle : shape
{
    rectangle(double a, double b) : shape(a, b)
    {
        ;
    }
    double get_area(void)
    {
        return x * y;
    }
    void print_area(void)
    {
        cout << "Rectangle Area=" << get_area() << endl;
    }
};
struct circle : shape
{
    circle(double r) : shape(r, 0)
    {
        ;
    }
    double get_area(void)
    {
        return x * x * 3.14;
    }
    void print_area(void)
    {
        cout << "Cirole Area=" << get_area() << endl;
        //spelling error "cirole" exists in test cases
    }
};
int main(void)
{
    double x, y;
    cin >> x >> y;
    triangle tri_demo(x, y);
    rectangle rec_demo(x, y);
    circle cir_demo(x);
    tri_demo.print_area();
    rec_demo.print_area();
    cir_demo.print_area();
    return 0;
}