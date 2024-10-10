#include<stdio.h>


int main()
{
  int n,m,oddSum=0,evenSum=0;
  printf("Enter the Number = ");
  scanf("%d",&n);

  while (n>0) {
   oddSum =oddSum + n % 10;
   n = n/10;
   evenSum = evenSum + n % 10;
   n =n/10;
  }
 printf("\nSum of digits in even  places:%d\n",evenSum);
 printf("Sum of digits in odd  places:%d\n",oddSum);
 return 0;
}
