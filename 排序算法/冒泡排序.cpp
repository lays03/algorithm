#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

void BubbleSort(vector<int>&v, int len)
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