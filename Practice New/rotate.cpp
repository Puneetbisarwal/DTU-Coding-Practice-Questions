#include<bits/stdc++.h>
using namespace std;
void rotatek(char *a,int k)
{
    int i=strlen(a);
    while(i>=0)
    {
        a[i+k]=a[i];
        i--;
    }
    i=strlen(a);
    int j=i-k;
    int s=0;
    while(j<i)
    {
        a[s]=a[j];
        s++;
        j++;
    }
    a[i-k]='\0';
}
int main()
{
    char a[100]="hello khkhkjkjkjkj";
    rotatek(a,2);
   cout<<a;
    return 0;
}
