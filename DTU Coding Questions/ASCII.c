#include <stdio.h>

int main()
{
   char i;
   printf("Enter the number=");
   scanf("%c",&i);

   if ( (i>64) && (i<91))
      printf("%c ASCII Code is %d is a UpperCase Character", i,i);
   else if ((i>96) && (i<123))
      printf("%c ASCII Code is %d is a LowerCase Character", i,i);

   return 0;
}
