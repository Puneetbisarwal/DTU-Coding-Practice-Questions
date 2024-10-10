#include<bits/stdc++.h>

using namespace std;


void swa(int &c,int &d)
{

    int temp = c;
    c= d;
    d=temp;
}

int main()
{
    int a=10,b=5;
    cout<<a<<" "<<b<<endl;
    swa(a,b);
    cout<<a<<" "<<b;
    return 0;
}
