#include <stdio.h>

int main()
{
   int a,b,c;
   printf("Enter the side of the Triangle = ");
   scanf("%d %d %d",&a,&b,&c);

   if(a>0 && b>0 && c>0)
   {


   if((a==b && b==c && a==c))
    printf("Equilateral Triangle ");

      else if((a==b && b!=c) || (a!=b && b==c) || (a==c && c!=b))
      printf("Isosceles Triangle");

      else
      printf("Scalene Triangle");
   }
   else
      printf("Wrong Input");
   return 0;
}
