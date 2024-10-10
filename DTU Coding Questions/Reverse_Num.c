#include<stdio.h>

int main()
{
//int i,n,a,b,c,d,e,f,g,h,j,k,l;
int i,n,rev=0;
printf("Enter the Number = ");
scanf("%d",&n);

while(n>0)
{
    rev=rev*10;
    rev=rev+n%10;
    n=n/10;
}
//printf("%d is the Reverse Number",l);
printf("%d is the Reverse Number",rev);
return 0;
}



