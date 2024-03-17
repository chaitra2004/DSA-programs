#include<stdio.h>
void fib(int);
main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    fib(n);
}
void fib(int n)
{
    int i;
    int x=0,y=1,z;
    printf("%d\t",x);
    printf("%d\t",y);
    for(i=3;i<=n;i++)
    {
        z=x+y;
        printf("%d\t",z);
        x=y;
        y=z;
    }
}
