#include <iostream>
#include <vector>
#include "mySort.h"
int main()
{
    vector<int> v{80, 30, 60, 40, 20, 10, 50, 70};
    int len = v.size();
    cout << "len = " << len << endl;
    mySort m;
    m.ShellSort(v, len);
    m.myPrint(v, len);
}
