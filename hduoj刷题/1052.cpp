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

//贪心的思想，如果能赢，我就一定要赢，如果赢不了，我要用我最垃圾的去赢你
//每次都让对面先出最大的，这样才比较好贪心

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
        if(tianji[0] > king[0]) //如果我方最大的能打赢对面最大的，那就先把最大的打掉
        {
            win++;
            tianji.erase(tianji.begin());
            king.erase(king.begin());
                
        }
        else if(tianji[0] < king[0]) //如果我方最大的打不赢对面，那么肯定都打不过了，那么就派最小的去出战
        {
            vector<int>::iterator it = tianji.end();
            --it; //派最后一匹马出战
            lose++;
            tianji.erase(it);
            king.erase(king.begin());
        }
        else //如果双方最厉害的马是一样厉害的
        {
            vector<int>::iterator it1 = tianji.end();
            vector<int>::iterator it2 = king.end();
            --it1;
            --it2;
            if(*it1 > *it2) //如果我最弱的马打的过你最弱的马，那就打 能赢就赢
            {
                win++;
                tianji.erase(it1);
                king.erase(it2);
            }
            else if(*it1 < *it2) //如果我最弱的马打不过你最弱的马，那就让我最弱的马去打你最强的马
            {
                lose++;
                tianji.erase(it1);
                king.erase(king.begin());
            }
            else //如果咱俩最弱的马一样弱
            {
                if(*it1 < king[0])
                {
                    lose++;
                    tianji.erase(it1);
                    king.erase(king.begin());
                }
                if(*it1 == king[0]) //如果我最弱的跟你最强的相等，说明剩余的马都一样，就平局
                {
                    tianji.erase(tianji.begin());
                    king.erase(king.begin());
                }  
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
        

        sort(tianji.begin(), tianji.end(), cmp);
        sort(king.begin(), king.end(), cmp);

        cout << func(tianji, king) << endl;

    }

}

