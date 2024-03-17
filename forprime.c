#include<stdio.h>
int isprime(int);
main()
{
    int n,m,i,res;
    printf("enter the value of n and m\n");
    scanf("%d%d",&n,&m);
    for(i=n;i<=m;i++)
    {
        res=isprime(i);
        if(res==0)
            printf(" %d is Not prime number\n",i);
        else
            printf(" %d is Prime number\n",i);
    }
}
int isprime(int n)
{
    int i,flag=0;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        return 1;
    else
        return 0;
}
