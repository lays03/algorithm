#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool BinarySearch(vector<int>&vec, int i, int j, int val)
{
    if(i > j)
    {
        return false;
    }
    int mid = (i + j) / 2;
    if(vec[mid] == val)
    {
        return true;
    }
    else if(vec[mid] < val)
    {
        return BinarySearch(vec, mid + 1, j, val);
    }
    else
    {
        return BinarySearch(vec, i, mid - 1, val);
    }
}

int main() {
    vector<int> vec;
    for(int i = 0; i < 11; ++i)
    {
        vec.push_back(rand() % 100);
    }
    sort(vec.begin(), vec.end());
    for(int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    bool result = BinarySearch(vec, 0, vec.size() - 1, 74);
    cout << result << endl;
}