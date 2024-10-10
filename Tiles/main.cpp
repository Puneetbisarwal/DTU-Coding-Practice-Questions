#include <iostream>

using namespace std;

int titles(int m)
{
    if(m == 0)
        return 0;
    if(m == 1)
        return 1;
    if(m == 2)
    return 2;

    int smallAns1 = titles(m-2);
    int smallAns2 = titles(m-1) ;
    return smallAns1 +smallAns2;
}

int main()
{
    int n;
    cin>>n;
    cout<<"No of tiles = "<<titles(n)<<endl;
    return 0;
}
