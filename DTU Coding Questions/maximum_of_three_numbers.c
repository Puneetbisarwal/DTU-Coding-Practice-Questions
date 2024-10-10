
#include <stdio.h>

int main(void) {
	// your code goes here

	int i,j,k;
	printf("Enter the number = ");
	scanf("%d %d %d",&i,&j,&k);

	if(i>j && i>k)
	printf("%d is the greatest number",i);
	else if(j>k)
	printf("%d is the greatest number",j);
	else
	printf("%d is the greatest number",k);
	return 0;
}
