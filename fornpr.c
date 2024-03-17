#include<stdio.h>
float npr(int,int);
int fact_num(int);
main()
{
    int n,r;
    float res;
    printf("enter the value of n and r\n");
    scanf("%d%d",&n,&r);
    res=npr(n,r);
    printf("nPr=%f",res);
}
float npr(int n,int r)
{
    int a,b;
    float res;
    a=fact_num(n);
    b=fact_num(n-r);
    res=a/b;
    return res;
}
int fact_num(int n)
{
    int i,f;
    for(i=1,f=1;i<=n;i++)
        f=f*i;
    return f;
}
