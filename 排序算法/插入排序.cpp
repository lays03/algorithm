#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

void InsertSort(vector<int>&v, int len)
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

    InsertSort(vec, vec.size());
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}