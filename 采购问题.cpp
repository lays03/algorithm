#include <iostream>
#include <map>
using namespace std;

int money = 0;
int n = 0;
map<int, int>mp;

void print(map<int, int>& mp)
{
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

int main()
{
    
    while (cin >> money >> n && n != 0)
    {
        int price = 0, num = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> price >> num;
            mp.insert(make_pair(price, num));
        }
        
        int res = 0;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
        {
            price = it->first;
            num = it->second;
            if(money >= price * num) //当前的钱够全买
            {
                money -= price * num;
                res += num;
            }
            else //不够全买
            {
                if(money / price == 0) //一件也买不起
                {
                    break;
                }
                else
                {
                    int temp =  money / price;
                    res += temp;
                    money -= price * temp;

                }
                
            }
        }
        cout << res << endl;
    }
    
}