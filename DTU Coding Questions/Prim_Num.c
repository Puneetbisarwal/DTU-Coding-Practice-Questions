
#include <stdio.h>

int main(void) {
	// your code goes here

	int n,i,flag=0;
	printf("Enter the number = ");
	scanf("%d",&n);
	if(n>0)
        {
	for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag=1;
        break;
        }
    }
if(n==1)
    printf("%d is neither a prime nor a composite number.",n);

	else
	{
	 if(flag==0)
        printf(" %d is the Prime Number ",n);
        else
	printf("%d Number is not Prime",n);

	}
        }
        else
            printf("Wrong Input");
	return 0;
}
