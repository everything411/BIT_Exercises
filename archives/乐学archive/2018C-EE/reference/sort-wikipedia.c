void bubble_sort(int arr[], int len)
{
        int i, j, temp;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (arr[j] > arr[j + 1])
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
}
void insertion_sort(int arr[], int len)
{
        int i, j, key;
        for (i = 1; i < len; i++)
        {
                key = arr[i];
                j = i - 1;
                while ((j >= 0) && (arr[j] > key))
                {
                        arr[j + 1] = arr[j];
                        j--;
                }
                arr[j + 1] = key;
        }
}
int min(int x, int y)
{
        return x < y ? x : y;
}
void merge_sort(int arr[], int len)
{
        int *a = arr;
        int *b = (int *)malloc(len * sizeof(int));
        int seg, start;
        for (seg = 1; seg < len; seg += seg)
        {
                for (start = 0; start < len; start += seg + seg)
                {
                        int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
                        int k = low;
                        int start1 = low, end1 = mid;
                        int start2 = mid, end2 = high;
                        while (start1 < end1 && start2 < end2)
                                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
                        while (start1 < end1)
                                b[k++] = a[start1++];
                        while (start2 < end2)
                                b[k++] = a[start2++];
                }
                int *temp = a;
                a = b;
                b = temp;
        }
        if (a != arr)
        {
                int i;
                for (i = 0; i < len; i++)
                        b[i] = a[i];
                b = a;
        }
        free(b);
}
void swap(int *a, int *b) //交換兩個變數
{
        int temp = *a;
        *a = *b;
        *b = temp;
}
void selection_sort(int arr[], int len)
{
        int i, j;

        for (i = 0; i < len - 1; i++)
        {
                int min = i;
                for (j = i + 1; j < len; j++)  //走訪未排序的元素
                        if (arr[j] < arr[min]) //找到目前最小值
                                min = j;       //紀錄最小值
                swap(&arr[min], &arr[i]);      //做交換
        }
}
void max_heapify(int arr[], int start, int end)
{
        //建立父節點指標和子節點指標
        int dad = start;
        int son = dad * 2 + 1;
        while (son <= end)
        {                                                      //若子節點指標在範圍內才做比較
                if (son + 1 <= end && arr[son] < arr[son + 1]) //先比較兩個子節點大小，選擇最大的
                        son++;
                if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
                        return;
                else
                { //否則交換父子內容再繼續子節點和孫節點比較
                        swap(&arr[dad], &arr[son]);
                        dad = son;
                        son = dad * 2 + 1;
                }
        }
}

void heap_sort(int arr[], int len)
{
        int i;
        //初始化，i從最後一個父節點開始調整
        for (i = len / 2 - 1; i >= 0; i--)
                max_heapify(arr, i, len - 1);
        //先將第一個元素和已排好元素前一位做交換，再重新調整，直到排序完畢
        for (i = len - 1; i > 0; i--)
        {
                swap(&arr[0], &arr[i]);
                max_heapify(arr, 0, i - 1);
        }
}
typedef struct _Range
{
        int start, end;
} Range;
Range new_Range(int s, int e)
{
        Range r;
        r.start = s;
        r.end = e;
        return r;
}
void quick_sort(int arr[], const int len)
{
        if (len <= 0)
                return; // 避免len等於負值時引發段錯誤（Segment Fault）
        // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
        Range r[len];
        int p = 0;
        r[p++] = new_Range(0, len - 1);
        while (p)
        {
                Range range = r[--p];
                if (range.start >= range.end)
                        continue;
                int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
                int left = range.start, right = range.end;
                do
                {
                        while (arr[left] < mid)
                                ++left; // 檢測基準點左側是否符合要求
                        while (arr[right] > mid)
                                --right; //檢測基準點右側是否符合要求

                        if (left <= right)
                        {
                                swap(&arr[left], &arr[right]);
                                left++;
                                right--; // 移動指針以繼續
                        }
                } while (left <= right);

                if (range.start < right)
                        r[p++] = new_Range(range.start, right);
                if (range.end > left)
                        r[p++] = new_Range(left, range.end);
        }
}