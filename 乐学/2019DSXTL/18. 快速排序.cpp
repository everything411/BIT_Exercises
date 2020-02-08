#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> median3_value;
vector<int> arr;
int median3(vector<int> &array, int left, int right)
{
    int center = (left + right) / 2;
    if (array[center] < array[left])
    {
        swap(array[left], array[center]);
    }
    if (array[right] < array[left])
    {
        swap(array[left], array[right]);
    }
    if (array[right] < array[center])
    {
        swap(array[center], array[right]);
    }
    swap(array[center], array[right - 1]);
    median3_value.push_back(array[right - 1]);
    return array[right - 1];
}
void quicksort(vector<int> &array, int left, int right)
{
    if (left + 5 <= right)
    {
        int pivot = median3(array, left, right);
        int i = left;
        int j = right - 1;
        while (true)
        {
            while (array[++i] < pivot)
                ;
            while (pivot < array[--j])
                ;
            if (i < j)
            {
                swap(array[i], array[j]);
            }
            else
            {
                break;
            }
        }
        swap(array[i], array[right - 1]);
        quicksort(array, left, i - 1);
        quicksort(array, i + 1, right);
    }
    else
    {
        sort(array.begin() + left, array.begin() + right + 1);
    }
}

void quicksort(vector<int> &a)
{
    quicksort(a, 0, a.size() - 1);
}
int main(int argc, char const *argv[])
{
    int a;
    while (scanf("%d", &a))
    {
        arr.push_back(a);
    }
    quicksort(arr);
    puts("After Sorting:");
    for (auto &&i : arr)
    {
        printf("%d ", i);
    }
    putchar('\n');
    puts("Median3 Value:");
    if (median3_value.size())
    {
        for (auto &&i : median3_value)
        {
            printf("%d ", i);
        }
        putchar('\n');
    }
    else
    {
        puts("none");
    }

    return 0;
}
