#pragma once
#include <iostream>
#include <vector>
using namespace std;

class mySort
{
public:
    void swap(int& a, int& b);
    void myPrint(vector<int>& v, int n);
public:
    //冒泡排序
    void BubbleSort(vector<int>& v, int n);

    //选择排序
    void SelectSort(vector<int>& v, int n);

    //直接插入排序
    void InsertSort(vector<int>& v, int n);

    //希尔排序
    void ShellSort(vector<int>& v, int n);
    void ShellInsert(vector<int>& v, int start, int gap);

};