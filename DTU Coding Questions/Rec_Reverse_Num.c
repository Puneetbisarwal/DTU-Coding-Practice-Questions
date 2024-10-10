#include<stdio.h>

long recur(long );
int main()
{
    long   n,r;
    printf("Enter the Number = ");
    scanf("%d",&n);

    r= recur(n);

    printf("%ld",r);
    return 0;
}

long recur(long num)
{

    static long r=0;

    if(num==0)
        return 0;

    r=r*10;
    r=r+num%10;
    recur(num/10);
    return r;
}




