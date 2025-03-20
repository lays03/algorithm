#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;

map<int, int>m;


int main()
{
    int n;
    int x, y;
    while(cin >> n)
    {
        m.clear();
        while(n--){
            cin >> x >> y;
            if(m.count(x) == 0)
            {
                m[x] = y;
            }
            else //表示有相同的索引
            {
                m[x] += y;
            }   
        }
        for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            cout << it->first << " " << it->second << endl;
        }
    }
}