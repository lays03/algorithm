#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

//冒泡排序
void BubbleSort(int v[], int len)
{
    for(int i = 0; i < len - 1; ++i)
    {
        for(int j = 0; j < len - i - 1; ++j)
        {
            if(v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

//插入排序
void SelectSort(int v[], int len)
{
    for(int i = 0; i < len - 1; ++i)
    {
        int min = i;
        for(int j = i + 1; j < len; ++j)
        {
            if(v[j] < v[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = v[min];
            v[min] = v[i];
            v[i] = temp;
        }
    }
}

//插入排序
void InsertSort(int v[], int len)
{
    for(int i = 1; i < len; ++i)
    {
        int val = v[i];
        int j = i - 1;
        for(; j >=0; --j)
        {
            if(v[j] <= val)
            {
                break;
            }
            else
            {
                v[j + 1] = v[j];
            }
        }
        v[j + 1] = val;
    }
}

//希尔排序
void ShellSort(int v[], int len)
{
    for(int gap = len / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < len; ++i)
        {
            int val = v[i];
            int j = i - gap;
            for(; j >=0; j -= gap)
            {
                if(v[j] <= val)
                {
                    break;
                }
                else
                {
                    v[j + gap] = v[j];
                }
            }
            v[j + gap] = val;
        }
    }
    
}

int main()
{
    const int COUNT = 100000;
    int* arr = new int [COUNT];
    int* brr = new int[COUNT];
    int* crr = new int[COUNT];
    int* drr = new int[COUNT];

    srand(time(NULL));

    for(int i = 0; i < COUNT; i++)
    {
        int val = rand() % COUNT;
        arr[i] = val;
        brr[i] = val;
        crr[i] = val;
        drr[i] = val;
    }

    clock_t begin, end;
    begin = clock();
    BubbleSort(arr, COUNT);
    end = clock();
    cout << "BubbleSort spend : " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

    begin = clock();
    SelectSort(brr, COUNT);
    end = clock();
    cout << "SelectSort spend : " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

    begin = clock();
    InsertSort(crr, COUNT);
    end = clock();
    cout << "InsertSort spend : " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

    begin = clock();
    ShellSort(drr, COUNT);
    end = clock();
    cout << "ShellSort spend : " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

    delete [] arr;
    delete [] brr;
    delete [] crr;
    delete [] drr;
}

#if 0
int main() {
    srand((unsigned)time(NULL));
    vector<int> vec;
    for(int i = 0; i < 11; ++i)
    {
        vec.push_back(rand() % 100);
    }
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    BubbleSort(vec, vec.size());
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}
#endif