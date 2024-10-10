
#include <stdio.h>

int main(void) {
	// your code goes here

	int i,num,n,flag=0;
	printf("Enter the number = ");
	scanf("%d",&n);

	if(n>0)
{
	for(num=1;num<=n;num++)
{
	flag=0;
	for(i=2;i<=num/2;i++)
	{
	if(num%i==0)
	 {
	   flag=1;
	   break;
	 }
	}

	if(flag==0 && num!=1)

        printf(" %d  ",num);
}

}
    else
	printf("Wrong Input");
	return 0;
}
