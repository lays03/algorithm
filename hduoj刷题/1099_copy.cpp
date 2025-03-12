/*
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

struct Room
{
public:
    double value;
    double JavaBean;
    double CatFood;
};

bool cmp(Room& r1, Room& r2)
{
    return r1.value < r2.value;
}

int main()
{
    
    while(cin >> M >> N && M != -1 & N != -1)
    {
        Room room[10001];
        double Ji, Fi;
        for(int i = 0; i < N; ++i)
        {
            cin >> Ji >> Fi;
            room[i].JavaBean = Ji;
            room[i].CatFood = Fi;
            room[i].value = room[i].CatFood / room[i].JavaBean;
        }
        sort(room, room + N, cmp);
        
        double res = 0; //最后的结果，能买到最多的javabean
        double Food = M; //初始的猫粮
        for(int i = 0; i < N; ++i)
        {
            if(Food >= room[i].CatFood) //自己的钱够买这件屋子里所有的javabean
            {
                res += room[i].JavaBean;
                Food -= room[i].CatFood;
            }
            else //如果不够买，那就买一部分
            {
                res += (Food / room[i].CatFood) * room[i].JavaBean;
                Food -= room[i].CatFood;
                break;
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(3);
        cout << res << endl;
    }
}