#pragma once
#include<iostream>
using namespace std;

class mySort
{
public:
    void swap(int& a, int& b);
    void myPrint(int arr[], int n);
public:
    //冒泡排序
    void BubbleSort(int arr[], int n);

    //选择排序
    void xuanzeSort(int arr[], int n);
};


