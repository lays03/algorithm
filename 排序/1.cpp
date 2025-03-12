#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void InsertSort(vector<int>& v, int n)
{
    for(int j = 1; j < n; ++j)
    {
        for(int i = 0; i < j; ++i)
        {
            if(v[j] < v[i])
            {
                int temp = v[j];
                for(int k = j - 1; k >= i; --k)
                {
                    v[k + 1] = v[k];
                }
                v[i] = temp;
                break;
            }
        }
    }
}

void ShellInsert(vector<int>& v, int start, int gap)
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

void ShellSort(vector<int>& v, int n)
{
    int gap = n / 2;
    for(; gap >= 1; gap /= 2)
    {
        for(int i = 0; i < gap; ++i)
        {
            ShellInsert(v, i, gap);
        }
    }
}



int main()
{
    vector<int> v{80, 30, 60, 40, 20, 10, 50, 70};
    int len = v.size();
    ShellSort(v, len);
    for(vector<int>::iterator it = v.begin(); it!= v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}