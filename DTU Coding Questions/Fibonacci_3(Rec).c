

int fib(int n)
{
int fib[n+1];
int i;
fib[0]=0;
fib[1]=1;

for(i=2;i<=n;i++)
{
fib[i] = fib[i-1] + fib[i-2];
}
return fib[n];
}

int fibbi(int n)
{
if(n<=1)
    return n;
return fibbi(n-1) + fibbi(n-2);

}

int main()
{

int n;

printf("Enter the number = ");
scanf("%d",&n);

printf("%d",fib(n));

printf("\nRecursion value= %d",fibbi(n));
}
