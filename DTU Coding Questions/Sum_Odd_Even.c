#include<stdio.h>


int main()
{
    int   n,a,b,c,d,e,f,g,h,sum,sum1;
    printf("Enter the Number = ");
    scanf("%d",&n);

    a=n/10;
    b=n%10;

    c=a/10;
    d=a%10;

    e=c/10;
    f=c%10;

    g=e/10;
    h=e%10;

    sum=b+f;
    sum1=d+h;

    printf("\n%d is the Sum of Even Place Digit",sum1);
    printf("\n%d is the Sum of Odd Place Digit",sum);
    return 0;
}

