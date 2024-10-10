
#include <stdio.h>

int main(void) {
	// your code goes here

	int i;
	printf("Enter the number = ");
	scanf("%d",&i);

	if((i%5==0) && (i%11==0))

        printf(" %d is Divisible by 5 and 11 ",i);

    else
	printf("Number is not Divisible by 5 and 11");
	return 0;
}
