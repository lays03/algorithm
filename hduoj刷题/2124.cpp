#include <iostream>
#include <algorithm>
#include <vector>
#include <istream>
using namespace std;

int L, N;


bool cmp(int v1, int v2)
{
    return v1 > v2;
}


int main()
{
    while (cin >> L >> N)
    {
        int Ni = 0;
        vector<int>v;
        for(int i = 0; i < N; ++i)
        {
            cin >> Ni;
            v.push_back(Ni);
        }
        sort(v.begin(), v.end(), cmp);

        int res = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            L -= v[i];
            res++;
            if(L <= 0)
            {
                cout << res << endl;
                break;
            }
        }
        if(L > 0)
        {
            cout << "impossible" << endl;
        }
        


    }
    
}