#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


int main() {
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
}