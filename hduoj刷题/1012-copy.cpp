#include <bits/stdc++.h>
 using namespace std;
 inline double gcd(int n)
 {
     int sum=1;
     for(int i=1;i<=n;i++)
         sum*=i;
     return sum;
 }
 int main()
 {
     cout<<'n'<<" "<<'e'<<endl;
     cout<<"- -----------"<<endl;
     cout<<0<<" "<<1<<endl;
     cout<<1<<" "<<2<<endl;
     cout<<2<<" "<<2.5<<endl;
     double sum=2.5;
    for(int i=3;i<=9;i++)
     {
         sum+=(1.0/(double)gcd(i));
         
         printf("%d %.9lf\n",i,sum);
     }
     return 0;
 }