#include<stdio.h>
int fact_num(int);
main()
{
    int n,f;
    printf("enter the value of n\n");
    scanf("%d",&n);
    if(n>=0)
    {
        f=fact_num(n);
        printf("%d!=%d",n,f);
    }
    else
        printf("invalid input\n");
}
int fact_num(int n)
{
    int i,f;
    for(i=1,f=1;i<=n;i++)
        f=f*i;
    return f;
}
