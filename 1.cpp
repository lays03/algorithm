#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//快排分割处理函数
int Partation(int v[], int l, int r)
{
    int val = v[l];
    //一次快排处理
    while(l < r)
    {
        while(l < r && v[r] > val)
        {
            r--;
        }
        if(l < r)
        {
            v[l] = v[r];
            l++;
        }

        while(l < r && v[l] < val)
        {
            l++;
        }
        if(l < r)
        {
            v[r] = v[l];
            r--;
        }
    }
    // l == r的位置，就是放基准数的位置
    v[l] = val;
    return l;
}

//快排的递归接口
void QuickSort(int v[], int begin, int end)
{
    if(begin >= end) //快排递归的条件
    {
        return;
    }
    //在[begin, end]区间做一次快排分割处理
    int pos = Partation(v, begin, end);

    //对基准数的左边和右边的序列，再分别进行快排
    QuickSort(v, begin, pos - 1);
    QuickSort(v, pos + 1, end);   
}
int main() {
    const int COUNT = 100;
    int* arr = new int [COUNT];
    srand(time(NULL));

    for(int i = 0; i < COUNT; i++)
    {
        int val = rand() % COUNT;
        arr[i] = val;
    }

    for(int i = 0; i < COUNT; ++i)
    {
        cout << arr[i] << endl;
    }
    cout << endl;


    clock_t begin, end;
    QuickSort(arr, 0, COUNT - 1);
    end = clock();
    for(int i = 0; i < COUNT; ++i)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
    cout << begin << endl;
    cout << end << endl;
    cout << "QuickSort spend : " << (end - begin) * 1.0 << "ms" << endl;
}

