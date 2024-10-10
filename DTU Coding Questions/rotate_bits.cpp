#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int right(int n,int d)
{
    int a=(1<<d)-1;
    cout<< "left shift "<<a<<endl;
    int x = n & a;
    cout<<"x = "<<x<<endl;

    x = x << (16-d);
    cout<<"x = "<<x<<endl;
    n = n>>d;
    cout<<" n = "<<n<<endl;
    int res = (n|x);
    cout<<"res = "<<res<<endl;
    return res;
}

int main() {
	//code

	int t,n,d;
    cin>>t;
    while(t--)
    {

    cin >> n >> d;
    cout<< (n<<d) <<endl;

    int ans = right(n,d);
    cout<<ans <<endl;

    }


	return 0;
}
