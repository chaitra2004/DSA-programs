#include<stdio.h>
void table(int);
main()
{
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    table(n);
}
void table(int n)
{
    int i,m;
    for(i=1;i<=10;i++)
    {
        m=i*n;
        printf("%d*%d=%d\n",i,n,m);
    }

}
