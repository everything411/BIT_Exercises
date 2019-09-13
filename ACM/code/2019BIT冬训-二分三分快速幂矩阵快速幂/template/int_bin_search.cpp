/*
int solve()
{
    //ret记录满足条件的最优解
    int left = 0, right = sum / k, ret = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (count(mid) >= k)
        {
            ret = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ret;
}
*/

/* by luoxn28 */

// 二分查找，找到该值在数组中的下标，否则为-1
int binarySerach(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;

    // 这里必须是 <=
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] == key)
        {
            return mid;
        }
        else if (array[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

// 查找第一个相等的元素
int findFirstEqual(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;

    // 这里必须是 <=
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] >= key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (left < len && array[left] == key)
    {
        return left;
    }

    return -1;
}

// 查找最后一个相等的元素
int findLastEqual(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;

    // 这里必须是 <=
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] <= key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (right >= 0 && array[right] == key)
    {
        return right;
    }

    return -1;
}

// 查找最后一个等于或者小于key的元素
int findLastEqualSmaller(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;

    // 这里必须是 <=
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}

// 查找最后一个小于key的元素
int findLastSmaller(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;

    // 这里必须是 <=
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] >= key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}

// 查找第一个等于或者大于key的元素
int findFirstEqualLarger(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;

    // 这里必须是 <=
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] >= key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

// 查找第一个大于key的元素
int findFirstLarger(int *array, int len, int key)
{
    int left = 0;
    int right = len - 1;

    // 这里必须是 <=
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}