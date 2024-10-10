#include<bits/stdc++.h>

using namespace std;

int main()
{
int num=0,rem;
int n;
cin>>n;
while(n>0)
{
    rem= n%10;
    num=num*10+rem;
    n=n/10;

}
cout<<num;
return 0;

}
