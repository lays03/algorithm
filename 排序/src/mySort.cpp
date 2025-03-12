#include "mySort.h"

void mySort::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b= temp;
}

void mySort::myPrint(vector<int>& v, int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

//冒泡排序
void mySort::BubbleSort(vector<int>& v, int n)
{
    //时间复杂度(平均): O(n^2)
    //空间复杂度(额外): 在swap创建过临时变量 O(1)
    //稳定性: 稳定
    for(int i = 0; i < n - 1; ++i)
    {
        bool flag = true; //假设已经有序了
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(v[j] > v[j + 1])
            {
                swap(v[j], v[j+1]);
                flag = false; //表示当前序列还是无序的
            }
        }
        //flag = true, 说明已经有序了 不用再继续判断了
        if(flag) break;
    }
}

//选择排序
void mySort::SelectSort(vector<int>& v, int n)
{
    //时间复杂度(平均): O(n^2)
    //空间复杂度(额外): 在swap创建过临时变量 O(1)
    //稳定性: 不稳定
    for(int i = 0; i < n; ++i)
    {
        int max = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(v[max] < v[j])
            {
                max = j;
            }
        }
        if(max != i)
        {
            swap(v[max], v[i]);
        }
    }
}

//直接插入排序
void mySort::InsertSort(vector<int>& v, int n)
{
    //时间复杂度(平均): O(n^2)
    //空间复杂度(额外): O(1)
    //稳定性: 稳定
    for(int j = 1; j < n; ++j) //构造无序区
    {
        for(int i = 0; i <= j - 1; ++i) //构造有序区
        {
            if(v[j] < v[i]) //讨论时间复杂度的时候, 不是每次都是执行的, 因此是有穷的
            {
                //下面两种后移方式都可以
                int index1 = i;
                int index2 = j;
                int temp = v[j];
                while(i < j)
                {
                    v[index2] = v[index2 - 1];
                    i++;
                    index2--;
                }
                v[index1] = temp;

                // int temp = v[j];
                // for(int k = j - 1; k >= i; k--)
                // {
                //     v[k + 1] = v[k];
                // }
                // v[i] = temp;
                // break;
            }
        }
    }
}

//希尔排序/缩小增量排序
void mySort::ShellSort(vector<int>& v, int n)
{
    //时间复杂度(平均): O(n^2)
    //空间复杂度(额外): O(1)
    //稳定性: 不稳定
    for(int gap = n/2; gap >= 1; gap /= 2)
    {
        for(int i = 0; i < gap; ++i)
        {
            ShellInsert(v, i, gap);
        }
        mySort ms;
        ms.myPrint(v, n);
    }
}

void mySort::ShellInsert(vector<int>& v, int start, int gap)
{
    for(int j = start + gap; j < v.size(); j+=gap)
    {
        for(int i = start; i < j; i+=gap)
        {
            if(v[j] < v[i])
            {
                int temp = v[j];
                for(int k = j - gap; k >= i; k-=gap)
                {
                    v[k + gap] = v[k];
                }
                v[i] = temp;
                break;
            }
            
        }
    }
}