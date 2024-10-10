#include <stdio.h>

int main()
{
   int year,i;
   printf("Enter the number = ");
   scanf("%d %d",&year,&i);

   if(year >0 && i>0)
   {

   if ( (i==2))
   {
       if((year%400 == 0)||( (year % 100!= 0)&&(year % 4 == 0) ))

       printf("29 is the Number of days.");
       else
       printf("28 is the Number of days.");

   }


   else if ( (i==1) || (i==3) || (i==5) || (i==7) || (i==8) || (i==10) || (i==12))
      printf(" 31 is the Number of days.");


      else if ((i==4) || (i==6) ||(i==9) || (i==11))
      printf(" 230 is the Number of days.");
}

      else
      printf("Wrong Input");

   return 0;
}
