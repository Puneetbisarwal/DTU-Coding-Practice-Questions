#include <stdio.h>

int main()
{
   int i,a,b,c,d,e,f,g,h,sum;
   printf("Enter the number = ");
   scanf("%d",&i);
if(i>0)
{
   a=(i/2000);
   b=(i%2000);

   c=(b/500);
   d=(b%500);

   e=(d/100);
   f=(d%100);

   g=(f/50);
   h=(f%50);

   sum=a+c+e+g;
      printf("%d is the total number of notes", sum);
}
else
    printf("Wrong Input");

   return 0;
}
