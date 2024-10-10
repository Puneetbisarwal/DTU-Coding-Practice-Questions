#include <stdio.h>

int main(void) {
	// your code goes here

	int i;
	printf("Enter the number = ");
	scanf("%d",&i);

	if(i%4==0)
    {
        if(i%100==0)
        {
            if(i%400==0)
            printf("%d is the Leap Year.",i);

        else
            printf("%d is the not the Leap Year.",i);
        }
        else
            printf("%d is the Leap Year.",i);
    }


    else
	printf(" Number is not the Leap Year. ");
	return 0;
}
