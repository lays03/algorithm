#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int a[101]; //s1的转换
int b[101]; //s2的转换
int c[101]; //高精度a和高精度b之和

void StrToInt(string src, int des[])
{
    for(int i = 0; i < src.size(); ++i)
    {
        des[src.size() - i - 1] = src[i]-'0';
    }
}

void mySub(int a[], int b[], int c[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        if(a[i] < b[i])
        {
            a[i + 1] -= 1;
            c[i] = a[i] + 10 - b[i];
        }
        else
        {
            c[i] = a[i] - b[i];
        }
    }
}

void reverse(int src[], int len)
{
    for(int i = 0; i < len / 2; ++i)
    {
        int temp = src[i];
        src[i] = src[len - i - 1];
        src[len - i - 1] = temp;
    }
}



int main()
{
    cout << "请输入s1 和 s2: " << endl;
    cin >> s1 >> s2;
    // 1. 反转-个位对齐，字符转整型
    StrToInt(s1, a);
    StrToInt(s2, b);
    int len_a = s1.size();
    int len_b = s2.size();
    
    // 2. 计算c数组长度，按最长数计算
    int len_c = max(len_a, len_b);

    // 3. 对位相减得出c数组
    if(s1.compare(s2) > 0)
    {
        mySub(a, b, c, max(len_a, len_b));
    }
    if(s1.compare(s2) < 0)
    {
        mySub(b, a, c, max(len_a, len_b));
    }
    

    // 4. 去除前导0 因为c数组的长度比a b最大长度大1位，防止最后一个运算有进位
    // 但是如果最后一位没有进位，那么那一位就是0
    while(c[len_c - 1] == 0 && len_c > 1)
    {
        len_c --;
    }
    reverse(c, len_c);
    cout << s1 << " - " << s2 << " = ";
    if(s1.compare(s2) < 0)
    {
        cout << "-";
    }
    for(int i = 0; i < len_c; ++i)
    {
        cout << c[i];
    }
    cout << endl;
}