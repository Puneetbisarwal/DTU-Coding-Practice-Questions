#include <stdio.h>

int main()
{
   int a,b,c;
   printf("Enter the side of the Triangle = ");
   scanf("%d %d %d",&a,&b,&c);

   if(a>0 && b>0 && c>0)
    {
      if((a+b>=c) && (a+c>=b) && (b+c>=a))
      printf("Triangle can be Formed");

      else
         printf("Cannot formed Triangle");
    }
      else
      printf("Wrong Input");

   return 0;
}
