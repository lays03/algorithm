#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> tianji; //田忌的马
vector<int> king; //国王的马

//如果能赢国王的马，就选择能赢的马中最弱的那只
//如果赢不了，就选择最弱的，让它的马赢我最弱的
//始终用最弱的去打最强的

bool cmp(int v1, int v2)
{
    return v1 > v2;
}

int func(vector<int>& tianji, vector<int>& king)
{
    //记录输赢的次数
    int win = 0;
    int lose = 0;
    for(int i = 0; i < n; ++i) //需要比n轮 对方每次都是出king[0]的马
    {
        //我方能打赢对方当前出战斗的马
        if(tianji[0] > king[0])
        {
            win++;
            tianji.erase(tianji.begin());
            king.erase(king.begin());
        }
        else if(tianji[0] < king[0]) //我方当前的马打不过对方的马
        {
            //那么看一下我方有没有比对方马厉害的
            bool flag = false; //记录是否有比对面厉害的
            vector<int>::iterator it = tianji.begin();
            for(; it != tianji.end(); ++it)
            {
                if(*it > king[0]) //如果找到了第一个能比对面马厉害的，就出战
                {
                    flag = true; //说明有打的过的
                    win++;
                    tianji.erase(it); //当前打的过的，打完就移出去
                    king.erase(king.begin());
                    break; //不需要再出战，需要break
                }
            }
            //如果遍历完后都没有找到能打赢对面的，那么就派一个最弱的出战
            if(flag == false) //说明没找到打的过的
            {
                lose++;
                tianji.erase(tianji.begin());
                king.erase(king.begin());
            }
        }
        else //如果当前出战的马一样，因为是贪心，所以我方还是需要遍历一下，是否有更厉害的能赢
        {
            bool flag = false; //记录是否有比对面厉害的
            vector<int>::iterator it = tianji.begin();
            for(; it != tianji.end(); ++it)
            {
                if(*it > king[0]) //如果找到了第一个能比对面马厉害的，就出战
                {
                    flag = true; //说明有比对面更厉害的
                    tianji.erase(it);
                    king.erase(king.begin());
                    win++;
                    break; //不需要再出战，需要break
                }
            }
            //如果遍历完后都没有找到能打赢对面的，那么就是平局
            if(flag == false)
            {
                tianji.erase(tianji.begin());
                king.erase(king.begin());
            }
            
        }
    }
    return (win - lose) * 200;
}

int main()
{
    int horse;
    while(cin >> n && n != 0)
    {
        tianji.erase(tianji.begin(), tianji.end());
        king.erase(king.begin(), king.end());
        for(int i = 0; i < n; ++i)
        {
            cin >> horse;
            tianji.push_back(horse);
        }

        for(int i = 0; i < n; ++i)
        {
            cin >> horse;
            king.push_back(horse);
        }
        

        sort(tianji.begin(), tianji.end());
        sort(king.begin(), king.end());

        cout << func(tianji, king) << endl;

    }

}

