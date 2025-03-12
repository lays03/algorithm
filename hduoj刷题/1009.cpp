/*
最开始用的map一直wa，后来换成multimap就好了
提交的时候记得选C++，因为涉及到double
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <istream>
#include <map>
#include<iomanip>
using namespace std;

int M, N;

int main()
{
    while(cin >> M >> N && M != -1 & N != -1)
    {
        multimap<double, multimap<double, double>>mp1; //按照每个房间的javabean的单价来生成mp
        
        double Ji, Fi;
        double price;
        for(int i = 0; i < N; ++i)
        {
            multimap<double, double>mp2;
            cin >> Ji >> Fi;
            price = Fi / Ji;
            mp2.insert(make_pair(Ji, Fi));
            mp1.insert(make_pair(price, mp2));
        }
        double res = 0; //最后的结果，能买到最多的javabean
        double money = M; //初始的猫粮
        for(multimap<double, multimap<double, double>>::iterator it = mp1.begin(); it != mp1.end(); ++it)
        {
            if(money >= it->second.begin()->second) //自己的钱够买这件屋子里所有的javabean
            {
                res += it->second.begin()->first;
                money -= it->second.begin()->second;
            }
            else //如果不够买，那就买一部分
            {
                res += (money / it->second.begin()->second) * it->second.begin()->first;
                money -= it->second.begin()->second;
                break;
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(3);
        cout << res << endl;
    }
}