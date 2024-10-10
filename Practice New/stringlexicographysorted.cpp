#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s[]={"abc" ,"acb","bca" ,"bac", "cab" , "cba"};
    sort(s,s+5 );
    for(int i=0;i<6;i++)
    {
        if(s[i]<"cab")
        {
        cout<<s[i]<<endl;
        }
    }
    return 0;
}
