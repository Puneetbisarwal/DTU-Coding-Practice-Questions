
#include<stdio.h>


int main()
{
  int a=0,b=1,fib=0,n,i,sum=0;
  printf("Enter the Number = ");
  scanf("%d",&n);

  n=n-2;
  printf(" %d %d ",a,b);
  for(i=0;i<n;i++)
  {
  sum=a+b;
  a=b;
  b=sum;
  printf("%d ",sum);
  }

 return 0;
}

