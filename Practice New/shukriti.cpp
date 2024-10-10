#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int,char> m;
    m[1]='a'+3;
    m[2]='m'+2;
    m[3]=' ';
    m[4]='w'+2;
    m[5]='q'-2;
    m[6]='t'+1;
    m[7]=' ';
    m[8]='i'+4;
    m[9]='h'+1;
    m[10]='p'+3;
    m[11]='r'+1;
    m[12]=' ';
    m[13]='j'+1;
    m[14]='q'-2;
    m[15]='q'+3;
    m[16]='d'-3;
    m[17]=' ';
    m[18]='f'-2;
    m[19]='c'-2;
    m[20]='x'+1;
    m[21]='q'+2;
    m[22]='?';
    for(int i=1;i<=22;i++)
    {
        cout<<m[i];
    }
    return 0;
}
