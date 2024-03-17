#include<stdio.h>
int sum(int,int);
main()
{
    int n,m,s;
    printf("enter the value n and m\n");
    scanf("%d%d",&n,&m);
    if(n<m)
        s=sum(n,m);
    else
        s=sum(m,n);
    printf("sum=%d",s);
}
int sum(int n,int m)
{
    int i,s;
    for(i=n,s=0;i<=m;i++)
        s=s+i;
    return s;
}
