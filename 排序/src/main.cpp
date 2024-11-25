#include <iostream>
#include "mySort.h"
int main()
{
    int arr[10] = {23, 21, 17, 3, 5, 11, 46, 6, 67, 71};
    mySort m;
    m.BubbleSort(arr, 10);
    m.myPrint(arr, 10);

    m.xuanzeSort(arr, 10);
    m.myPrint(arr, 10);

}
