
#include <stdio.h>

int main(void) {
	// your code goes here

	int i;
	printf("Enter the number = ");
	scanf("%d",&i);

	if(i>0)
	printf(" %d is the Positive number",i);
	else if(i==0)
	printf(" %d is the Zero number",i);
	else
	printf(" %d is the Negative number",i);
	return 0;
}
