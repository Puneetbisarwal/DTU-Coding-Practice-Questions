#include<iostream>
using namespace std;
void mergetwosortedarray(int *a1,int n1,int *a2,int n2,int *a)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a1[i]>a2[j])
        {
            a[k]=a2[j];
            j++;
            k++;
        }
        else
        {
            a[k]=a1[i];
            i++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=a2[j];
        k++;
        j++;
    }
}
int main()
{
    int a1[]={1,3,5,7,9,11};
    int a2[]={2,4,6,8,10,12};
    int a3[12];
    mergetwosortedarray(a1,6,a2,6,a3);
    for(int i=0;i<12;i++){cout<<a3[i]<<" ";}
    return 0;
}
