#include "mySort.h"

void mySort::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b= temp;
}

void mySort::myPrint(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//冒泡排序
void mySort::BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//选择排序
void mySort::xuanzeSort(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        int max = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if(max != i)
        {
            swap(arr[max], arr[i]);
        }
    }
}