#include<bits/stdc++.h>
using namespace std;
union temp
{
    int a;
    int  *b;
    char c;
}__attribute__((packed));
enum first
{
    a,b,c,d
};
int main()
{
    union temp s1;
    cout<<sizeof(s1)<<endl;
    //enum first e;
    enum first e=d;
    cout<<e;
    return 0;
}
