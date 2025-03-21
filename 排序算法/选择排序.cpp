#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

void SelectSort(vector<int>&v, int len)
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

    SelectSort(vec, vec.size());
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}