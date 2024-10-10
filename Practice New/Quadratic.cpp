/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//int main() {
    /*int a,b,c;
    cin>>a>>b>>c;
    int ans=b*b-4*a*c;
    if(ans==0)
    {
        cout<<"Real ans Equal"<<endl;
    }
    else if(ans>0)
    {
        cout<<"Real ans Distinct"<<endl;
    }
    else
    {
        cout<<"Imaginary";
        return 0;
    }
    float ans1;
    ans1=((-1*b)+(sqrt(ans)))/(2.0*a);
    float ans2;
    ans2=((-1*b)-(sqrt(ans)))/(2.0*a);
    cout<<ans2<<" "<<ans1;*/

    /*int n1,n2;
    cin>>n1>>n2;
    int count=0;
    int n=1;
    while(count!=n1)
    {
        if((3*n+2)%n2!=0)
        {
            cout<<3*n+2<<endl;
            count++;
        }
        n++;
    }*/

/*int digit(int n)
{
    int count=0;
    while(n>0)
    {
        n/=10;
        count++;
    }
    return count;
}
int main() {
    int n;
    cin>>n;
    int v=n;
    int ans=0;
    int p=digit(n);
    while(n>0)
    {
        ans=ans+pow(n%10,p);
        n=n/10;
    }
    if(ans==v)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

	return 0;*/
/*
int main() {
    char a;
    cin>>a;
    while(a!='X' && a!='x')
    {
        if(a=='+')
        {
            int n1,n2;
            cin>>n1>>n2;
            cout<<n1+n2<<endl;
        }
        else if(a=='-')
        {
            int n1,n2;
            cin>>n1>>n2;
            cout<<n1-n2<<endl;
        }
        else if(a=='*')
        {
            int n1,n2;
            cin>>n1>>n2;
            cout<<n1*n2<<endl;
        }
        else if(a=='/')
        {
            int n1,n2;
            cin>>n1>>n2;
            cout<<n1/n2<<endl;
        }
        else
        {
            cout<<"Invalid operation. Try again."<<endl;
        }
        cin>>a;
    }

	return 0;
}

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int c1,c2,c3,c4;
    int rick,cab;
    int rish[1000],tax[1000];
    while(n--)
    {
        cin>>c1>>c2>>c3>>c4;
        cin>>rick>>cab;
        for(int i=0;i<rick;i++)
        {
            cin>>rish[i];
        }
        for(int i=0;i<cab;i++)
        {
            cin>>tax[i];
        }
        int ans1=0;
        for(int i=0;i<rick;i++)
        {
            ans1=ans1+min(rish[i]*c1,c2);
        }
        int ans2=0;
        for(int i=0;i<cab;i++)
        {
            ans2=ans2+min(tax[i]*c1,c2);
        }

         ans1=min(ans1,c3);
         ans2=min(ans2,c3);
        cout<<ans1<<" "<<ans2<<endl;
        cout<<min(c4,ans1+ans2)<<endl;
    }
	return 0;
}
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n--)
    {
        int c1,c2,c3,c4;
        cin>>c1>>c2>>c3>>c4;
        int rick,cab;
        cin>>rick>>cab;
        int rish[rick],tax[cab];
        for(int i=0;i<rick;i++)
        {
            cin>>rish[i];
        }
        for(int i=0;i<cab;i++)
        {
            cin>>tax[i];
        }
        int ans1=0;
        while(rick--)
        {
            int i=0;
            ans1=ans1+min(rish[i]*c1,c2);
            i++;
        }
        int ans2=0;
        while(cab--)
        {
            int i=0;
            ans2=ans2+min(tax[i]*c1,c2);
            i++;
        }
        int ans3=min(ans1,c3);
        int ans4=min(ans2,c3);
        cout<<min(c4,ans3+ans4)<<endl;
    }
	return 0;
}*/
