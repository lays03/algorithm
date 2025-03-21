#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

//快排分割处理函数
int Partation(vector<int>&vec, int l, int r)
{
    int val = vec[l];
    //一次快排处理
    while(l < r) //O(n)
    {
        while(l < r && vec[r] > val)
        {
            r--;
        }
        if(l < r)
        {
            vec[l] = vec[r];
            l++;
        }

        while(l < r && vec[l] < val)
        {
            l++;
        }
        if(l < r)
        {
            vec[r] = vec[l];
            r--;
        }
    }
    // l == r的位置，就是放基准数的位置
    vec[l] = val;
    return l;
}

//快排的递归接口
void QuickSort(vector<int>&vec, int begin, int end)
{
    //O(logn)
    if(begin >= end) //快排递归的条件
    {
        return;
    }
    //在[begin, end]区间做一次快排分割处理
    int pos = Partation(vec, begin, end);

    //对基准数的左边和右边的序列，再分别进行快排
    QuickSort(vec, begin, pos - 1);
    QuickSort(vec, pos + 1, end);   
}

int main() {
    srand((unsigned)time(NULL));
    vector<int>vec;
    for(int i = 0; i < 11; ++i)
    {
        vec.push_back(rand() % 100);
    }
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    QuickSort(vec, 0, vec.size() - 1);
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}