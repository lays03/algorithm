#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

void ShellSort(vector<int>&v, int len)
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

    ShellSort(vec, vec.size());
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}