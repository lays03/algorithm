#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int jiecheng(int n)
{
    int sum = 1;
    for(int i = 1; i <= n; ++i)
    {
        sum *= i;
    }
    return sum;
}

int main()
{
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    cout << "0 1" << endl;
    cout << "1 2" << endl;
    cout << "2 2.5" << endl;
    double sum = 2.5;
    for(int i = 3; i <= 9; ++i)
    {
        sum += (1.0 / double(jiecheng(i)));
         
        printf("%d %.9lf\n",i,sum);
    }

}


// n e
// - -----------
// 0 1
// 1 2
// 2 2.5
// 3 2.666666667
// 4 2.708333333
// 5 2.716666667
// 6 2.718055556
// 7 2.718253968
// 8 2.718278770
// 9 2.718281526